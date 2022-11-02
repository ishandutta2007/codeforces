#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}

#define MAXN 9999
#define MAXSIZE 50
#define DLEN 4 
#define int long long 
class BigInt
{
    private:
        int a[MAXSIZE+1];
        int len;
        bool sign;
        //sign~
    protected:
        BigInt add(const BigInt&,const bool)const;
        BigInt subtract(const BigInt&,const bool)const;
         //,flag~~
    public:
        BigInt() {sign=false;len=1;memset(a,0,sizeof(a));}
        BigInt(const int);
        BigInt(const char*);
        BigInt(const BigInt&);
        BigInt& operator=(const BigInt&);
        friend istream& operator>>(istream&,BigInt&);
        friend ostream& operator<<(ostream&,const BigInt&);
        friend BigInt abs(const BigInt&);
 
        BigInt operator+(const BigInt&)const;
        BigInt operator-(const BigInt&)const;
        BigInt operator*(const BigInt&)const;
        BigInt operator/(const BigInt&)const;
        BigInt operator/(const int&)const;
 
        BigInt operator^(const int&)const;
        int operator%(const int&)const;
        bool operator<(const BigInt&)const;
        bool operator>(const BigInt&)const;
        bool operator<=(const BigInt&)const;
        bool operator>=(const BigInt&)const;
        bool operator==(const BigInt&)const;
 
        inline int size() {return DLEN*(len-1)+to_string(a[len-1]).size();}
};
//~~~
BigInt::BigInt(const int b)
{
    int c,d=abs(b);
    len=0;
    sign=b<0;
    memset(a,0,sizeof(a));
    while(d>MAXN)
    {
        c=d-(d/(MAXN+1))*(MAXN+1);
        d=d/(MAXN+1);
        a[len++]=c;
    }
    a[len++]=d;
}
BigInt::BigInt(const char *in)
{
    const char *s;
    if(in[0]=='-') s=in+1,sign=true;
    else s=in,sign=false;
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L=strlen(s);
    len=L/DLEN;
    if(L%DLEN) len++;
    index=0;
    for(i=L-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0) k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigInt::BigInt(const BigInt& T):len(T.len),sign(T.sign)
{
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++)
        a[i]=T.a[i];
}
BigInt& BigInt::operator=(const BigInt& n)
{
    sign=n.sign;
    len=n.len;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++)
        a[i]=n.a[i];
    return *this;
}
//MDZZ~BigInt,233333
istream& operator>>(istream& in,BigInt& b)
{
    char ch[MAXSIZE];
    in>>ch;
    b=BigInt(ch);
    return in;
}
ostream& operator<<(ostream& out,const BigInt& b)
{
    out<<(b.sign?"-":"")<<b.a[b.len-1];
    for(int i=b.len-2;i>=0;i--) out<<setw(DLEN)<<setfill('0')<<b.a[i];
    return out;
}
BigInt abs(const BigInt& T)
{
    BigInt t(T);
    t.sign=false;
    return t;
}
BigInt BigInt::add(const BigInt& T,const bool flag)const
{
    BigInt t(*this);
    t.sign=flag;
    int big;
    big=T.len>len?T.len:len;
    for(int i=0;i<big;i++)
    {
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN)
        {
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    if(t.a[big]!=0) t.len=big+1;
    else t.len=big;
    return t;
}
BigInt BigInt::subtract(const BigInt& T,const bool flag)const
{
    BigInt t(*this);
    t.sign=flag;
    for(int i=0;i<t.len;i++)
    {
        if(t.a[i]<T.a[i])
        {
            //~
            int j=i+1;
            while(t.a[j]==0) j++;
            t.a[j--]--;
            while(j>i) t.a[j--]+=MAXN;
            t.a[i]+=MAXN+1-T.a[i];
        }
        else t.a[i]-=T.a[i];
    }
    while(t.a[t.len-1]==0&&t.len>1) t.len--;
    return t;
}
BigInt BigInt::operator+(const BigInt& T)const
{
    BigInt ret;
    if(sign^T.sign)
    {
        BigInt t1(*this),t2(T);
        if(abs(t1)<abs(t2)) swap(t1,t2);
        ret=t1.subtract(t2,t1.sign);
        if(ret.a[ret.len-1]==0&&ret.len==1) ret.sign=false;
    }
    else ret=this->add(T,sign);
    return ret;
}
BigInt BigInt::operator-(const BigInt& T)const
{
    BigInt ret;
    if(sign^T.sign) ret=this->add(T,sign);
    else
    {
        BigInt t1(*this),t2(T);
        bool sn;
        if(abs(t1)<abs(t2))
        {
            sn=t1.sign^1;
            swap(t1,t2);
        }
        else sn=t1.sign;
        ret=t1.subtract(t2,sn);
        if(ret.a[ret.len-1]==0&&ret.len==1) ret.sign=false;
    }
    return ret;
}
BigInt BigInt::operator*(const BigInt& T)const
{
    BigInt ret;
    long long up;
    long long temp,temp1;
    for(int i=0;i<len;i++)
    {
        up=0;
        for(int j=0;j<T.len;j++)
        {
            temp=(long long)a[i]*T.a[j]+ret.a[i+j]+up;
            if(temp>MAXN)
            {
                temp1=temp%(MAXN+1);
                up=temp/(MAXN+1);
                ret.a[i+j]=temp1;
            }
            else
            {
                up=0;
                ret.a[i+j]=temp;
            }
        }
        if(up!=0) ret.a[i+T.len]=up;
    }
    ret.sign=sign^T.sign;
    ret.len=len+T.len;
    while(ret.a[ret.len-1]==0&&ret.len>1) ret.len--;
    return ret;
}
BigInt BigInt::operator/(const BigInt& T)const
{
    BigInt r(*this),ret((ll)0);
    while(r>=T)
    {
        BigInt down(1);
        while(r-T*down>=(ll)0) down=down*10;
        down=down/10;
        r=r-T*down;
        ret=ret+down;
    }
    ret.sign=sign^T.sign;
    return ret;
}
BigInt BigInt::operator/(const int &b)const
{
    BigInt ret;
    bool sign1=b<0;
    long long down=0;
    for(int i=len-1;i>=0;i--)
    {
        ret.a[i]=(a[i]+down*(MAXN+1))/b;
        down=a[i]+down*(MAXN+1)-(long long)ret.a[i]*b;
    }
    ret.sign=sign^sign1;
    ret.len=len;
    while(ret.a[ret.len-1]==0&&ret.len>1) ret.len--;
    return ret;
}
int BigInt::operator%(const int &b)const
{
    int d=0;
    for(int i=len-1;i>=0;i--)
        d=(((long long)d*(MAXN+1))%b+a[i])%b;
    return sign?-d:d;
}
BigInt BigInt::operator^(const int &n)const
{
    BigInt ret(1),t(*this);
    int m=n;
    while(m)
    {
        if(m&1) ret=ret*t;
        t=t*t;
        m>>=1;
    }
    return ret;
}
bool BigInt::operator<(const BigInt& T)const
{
    if(sign&&!T.sign) return true;
    if(!sign&&T.sign) return false;
    //sign~~
    if(len!=T.len) return sign^(len<T.len);
    for(int ln=len-1;ln>=0;ln--)
        if(a[ln]!=T.a[ln]) return sign^(a[ln]<T.a[ln]);
    return false;
}
bool BigInt::operator>(const BigInt& T)const
{
    return T<*this;
}
bool BigInt::operator<=(const BigInt& T)const
{
    if(*this==T) return true;
    return *this<T;
}
bool BigInt::operator>=(const BigInt& T)const
{
    return T<=*this;
}
bool BigInt::operator==(const BigInt& T)const
{
    if(sign!=T.sign||len!=T.len) return false;
    for(int i=len-1;i>=0;i--)
        if(a[i]!=T.a[i]) return false;
    return true;
}
//#undef int
const int N=300005;
BigInt q[N],f[N],s,b,al;
int top,l,r;
signed main(){
	int n=read(),m=read(); 
	q[++top]=1;
	int l=1,r=n;
	while(m--){
		int op=read();
		if(op==1){
			int t=read();
			l-=t; 
			q[top=1]=l;
			f[1]=al-s-b*q[1];
		}else if(op==2){
			BigInt x=r+1,y=al-s-b*(r+1); r+=read(); // cout<<x*b+y+s<<endl;
			while(top>=2&&(f[top]-f[top-1])*(x-q[top])>=(y-f[top])*(q[top]-q[top-1]))top--;
			q[++top]=x; f[top]=y;
		}else{
			s=s+read(); int t=read(); b=b+t;  s=s-t*l;
		}
		//cout<<q[top]*b+f[top]+s<<endl;
		while(top>=2&&q[top]*b+f[top]>=q[top-1]*b+f[top-1])top--;
		//cout<<l<<" fjzzq "<<r<<" "<<b<<" "<<s<<" "<<q[top]<<" "<<q[top-1]<<endl;
		cout<<q[top]-l+1; putchar(' '); cout<<q[top]*b+f[top]+s; puts("");
	}
}
/*
6 8
3 2 5
1 2
2 7
2 4
1 1
1 7
3 1 1
3 1 2

*/