//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
char s[1000005];
const int MOD1=666623333;
const int MOD2=993244853;
int base1,base2;
int hs1[1000005],hs2[1000005],P1[1000005],P2[1000005],n;
inline pii gethash(int l,int r){
	return {(hs1[r]-hs1[l-1]*P1[r-l+1]%MOD1+MOD1)%MOD1,(hs2[r]-hs2[l-1]*P2[r-l+1]%MOD2+MOD2)%MOD2};
}
inline bool check(pii a,pii b,pii c){
	return pii((a.fi+b.fi)%MOD1,(a.se+b.se)%MOD2)==c;
}
inline void deal(int l1,int r1,int l2,int r2,int l3,int r3){
	if(s[l1]=='0'&&r1-l1+1>1)	return;
	if(s[l2]=='0'&&r2-l2+1>1)	return;
	if(s[l3]=='0'&&r3-l3+1>1)	return;
//	cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<l3<<" "<<r3<<endl;
	pii h1=gethash(l1,r1),h2=gethash(l2,r2),h3=gethash(l3,r3);
//	cout<<h1.fi<<" "<<h1.se<<" "<<h2.fi<<" "<<h2.se<<" "<<h3.fi<<" "<<h3.se<<endl;
	if(check(h1,h2,h3)){
		fz(i,l1,r1)	putchar(s[i]);
		putchar('+');
		fz(i,l2,r2)	putchar(s[i]);
		putchar('=');
		fz(i,l3,r3)	putchar(s[i]);
		exit(0);
	}
}
signed main(){
	base1=base2=10;
	cin>>s+1;
	n=strlen(s+1);
	P1[0]=P2[0]=1;
	fz(i,1,n){
		P1[i]=P1[i-1]*base1%MOD1;
		P2[i]=P2[i-1]*base2%MOD2;
		hs1[i]=(hs1[i-1]*base1+s[i]-'0')%MOD1;
		hs2[i]=(hs2[i-1]*base2+s[i]-'0')%MOD2;
	}
	fz(i,1,n){
		if(i+i<n){
			deal(1,n-i-i,n-i-i+1,n-i,n-i+1,n);
			deal(1,i,i+1,n-i,n-i+1,n);
		}
		if(i+(i-1)<n){
			deal(1,i-1,i,n-i,n-i+1,n);
			deal(1,n-i-i+1,n-i-i+2,n-i,n-i+1,n);
		}
	}
	return 0;
}