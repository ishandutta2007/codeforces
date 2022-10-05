/*
Contest:
Problem:
Author: tzc_wk
Time:
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
#define y1			y1010101010101
#define y0			y0101010101010
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),x=read(),y=read(),vx=read(),vy=read();
inline int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int t=exgcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	return t;
}
signed main(){
	if(!vx&&vy==1){
		if(x==n)		cout<<n<<" "<<m<<endl;
		else if(x==0)	cout<<0<<" "<<m<<endl;
		else			puts("-1");
		return 0;
	}
	if(!vx&&vy==-1){
		if(x==n)		cout<<n<<" "<<0<<endl;
		else if(x==0)	cout<<0<<" "<<0<<endl;
		else			puts("-1");
		return 0;
	}
	if(vx==1&&!vy){
		if(y==0)		cout<<n<<" "<<0<<endl;
		else if(y==m)	cout<<n<<" "<<m<<endl;
		else			puts("-1");
		return 0;
	}
	if(vx==-1&&!vy){
		if(y==0)		cout<<0<<" "<<0<<endl;
		else if(y==m)	cout<<0<<" "<<m<<endl;
		else			puts("-1");
		return 0;
	}
	if(vx==-1)	x=n-x;
	if(vy==-1)	y=m-y;
	int gcd=__gcd(n,m);
	if((x-y)%gcd!=0)	return puts("-1")*0;
	int kx,ky;
	exgcd(n,m,kx,ky);
//	cout<<kx<<" "<<ky<<endl;
	kx*=(x-y)/gcd;
	ky*=(x-y)/gcd;
	int xx=(kx%(m/gcd)+m/gcd+m/gcd-1)%(m/gcd)+1,yy=-((x-y)-xx*n)/m;
//	cout<<kx<<" "<<ky<<endl;
	int ansx,ansy;
	if(xx%2)	ansx=n;
	else		ansx=0;
	if(yy%2)	ansy=m;
	else		ansy=0;
	if(vx==-1)	ansx=n-ansx;
	if(vy==-1)	ansy=m-ansy;
	cout<<ansx<<" "<<ansy<<endl;
	return 0;
}
/*
(0,y-x)
an-bm=x-y
*/
/**/