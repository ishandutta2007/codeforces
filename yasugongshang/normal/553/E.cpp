#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
#define mp make_pair
#define poly vector<ld>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=55,M=105,T=20005;
ld dq[M][T],ans[N][T],p[M][T];
int n,m,t,X,c[M],x[M],y[M],f[N][N];
struct cp{
    ld x,y;
    cp(): x(0), y(0) { }
    cp(ld xx,ld yy):x(xx),y(yy){}
    void operator =(ld xx){
        x=xx; y=0;
    }
};
inline cp operator+(const cp &a, const cp &b) { return cp(a.x + b.x, a.y + b.y); }
inline cp operator-(const cp &a, const cp &b) { return cp(a.x - b.x, a.y - b.y); }
inline cp operator*(const cp &a, const cp &b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline cp conj(const cp &a) { return cp(a.x, -a.y); }
const double PI=acos(-1);
const int NN=1<<15|3;
cp omg[NN],inv[NN],a[NN],b[NN];
int rev[NN];
void init(int n){
    int len=0; while((1<<len)<n)len++;
    for(int i=0;i<n;i++){
        omg[i]=cp(cos(2*PI*i/n),sin(2*PI*i/n));
        inv[i]=conj(omg[i]);
        rev[i]=rev[i>>1]>>1|((i&1)<<(len-1));
    }
}
void FFT(cp *a,int flag,int n){
    cp *dq;
    if(flag)dq=omg; else dq=inv;
    for(int i=0;i<n;i++)if(rev[i]<i)swap(a[i],a[rev[i]]);
    for(int l=2;l<=n;l*=2){
        int m=l/2;
        for(int p=0;p<n;p+=l){
            for(int i=p;i<p+m;i++){
                cp t=dq[n/l*(i-p)]*a[i+m];
                a[i+m]=a[i]-t; a[i]=a[i]+t;
            }
        }
    }
    if(!flag){
        for(int i=0;i<n;i++)a[i].x/=n;
    }
}
void FFT(cp *a,cp *b,int as,int bs,int cs){
    int len=1;
    while(len<cs)len<<=1;
    init(len);
    for(int i=as;i<len;i++)a[i]=0; for(int i=bs;i<len;i++)b[i]=0;
    FFT(a,1,len); FFT(b,1,len);
    for(int i=0;i<len;i++)a[i]=a[i]*b[i]; 
    FFT(a,0,len);
}
void solve(int l,int r){
	if(l==r){
		For(i,1,n-1)ans[i][l]=1e18; For(i,1,m)ans[x[i]][l]=min(ans[x[i]][l],dq[i][l]); return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	For(j,1,m){
		For(k,mid+1,r)a[k-mid-1]=ans[y[j]][k]+c[j]; 
		For(k,0,r-l-1)b[k]=p[j][r-l-k];
		FFT(a,b,r-mid,r-l,r-l+1);//-1->r-l-1  mid+1 +  (-1) ->mid 0+r-l-1 r-mid-1
		For(k,l,mid)dq[j][k]+=a[k+r-l-1-mid].x;
	}
	solve(l,mid);
}
int main(){
	n=read(); m=read(); t=read(); X=read();
	For(i,1,n)For(j,1,n)if(i!=j)f[i][j]=1e9;
	For(i,1,m){
		x[i]=read(); y[i]=read(); c[i]=read();
		For(j,1,t)p[i][j]=(ld)read()/100000;
		f[x[i]][y[i]]=min(f[x[i]][y[i]],c[i]);
	}
	For(k,1,n)For(i,1,n)For(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	For(i,1,n)ans[i][t+1]=f[i][n]+X;
	For(i,1,m){
		For(j,1,t){
			dq[i][j]=dq[i][j-1]+p[i][t-j+1]*(ans[y[i]][t+1]+c[i]);
			//if(i==2)cout<<p[i][t-j+1]<<" "<<ans[y[i]][t+1]<<" "<<c[i]<<" fasoigoiugusbgoiasbgiaobgsokgtnaop"<<endl;
		}
	}
	//cout<<ans[4][t+1]<<"  nfnasuigba"<<" "<<p[4][3]<<" "<<c[4]<<endl;
	/*For(i,1,m){
		For(j,0,t)cout<<dq[i][j]<<" "; puts(" fjzzq ");
	}*/
	solve(0,t);
	/*For(i,1,n){
		For(j,0,t)cout<<ans[i][j]<<" "; puts("");
	}*/
	printf("%.10f\n",(double)ans[1][0]);
}
/*
ax^kx-

*/