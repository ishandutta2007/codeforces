#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
int mod,d;
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 20
int fac[N],inv[N],pinv[N];
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
void add(int a,int b,int to) {printf("+ %d %d %d\n",a,b,to);}
void D(int a,int to) {printf("^ %d %d\n",a,to);}
void init() // used 4900-5000 , a5000 = 0
{
	for(int i=1;i<=32;i++) add(4900+i-1,4900+i-1,4900+i);
	for(int i=0;i<=30;i++)
	{
		if((mod-1)>>i&1) add(5000,4900+i,5000);
	}
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
int a[15][15],ans[15];
void init2()
{
	for(int i=1;i<=d+1;i++)
	{
		for(int j=1;j<=d+1;j++) a[i][j]=mul(C(d,i-1),qpow(j,i-1));
		a[i][d+2]=i==d-1;
	}
//	for(int i=1;i<=d+1;i++)
//	{
//		for(int j=1;j<=d+2;j++) printf("%d ",a[i][j]);
//		cout<<"\n";
//	}
	for(int i=1;i<=d+1;i++)
	{
		int pl=0;
		for(int j=i;j<=d+1;j++)
		{
			if(a[j][i]) {pl=j; break;}
		}
		for(int j=i;j<=d+2;j++) swap(a[i][j],a[pl][j]);
		int inv=Inv(a[i][i]);
		for(int j=i;j<=d+2;j++) a[i][j]=mul(a[i][j],inv);
		for(int j=1;j<=d+1;j++)
		{
			if(j==pl) continue;
			int D=a[j][i];
			for(int k=i;k<=d+2;k++) a[j][k]=sub(a[j][k],mul(D,a[i][k]));
		}
	}
	for(int i=1;i<=d+1;i++) ans[i]=a[i][d+2];
}
void getval(int pl,int v) // a_pl = v
{
	add(5000,5000,pl);
	for(int i=0;i<=30;i++)
	{
		if(v>>i&1) add(pl,4900+i,pl);
	}
}
void mulval(int pl,int v,int to) // a_to = a_pl * v , used 4800-4899
{
	add(5000,pl,4800);
	for(int i=1;i<=30;i++) add(4800+i-1,4800+i-1,4800+i);
	add(5000,5000,to);
	for(int i=0;i<=30;i++)
	{
		if(v>>i&1) add(to,4800+i,to);
	}
}
void divval(int pl,int v,int to)
{
	mulval(pl,Inv(v),to);
}
void addval(int pl,int v,int to) // a_to = a_pl + v , used 4799
{
	getval(4799,v);
	add(pl,4799,to);
}
void subval(int pl,int v,int to) // a_to = a_pl - v 
{
	addval(pl,mod-v,to);
}
void getsqr(int pl,int to) // a_to = a_pl ^ 2 , used 3000 +
{
	for(int i=1;i<=d+1;i++) addval(pl,i,4100+i);
	for(int i=1;i<=d+1;i++) D(4100+i,4000+i);
	for(int i=1;i<=d+1;i++) mulval(4000+i,ans[i],3000+i);
	add(5000,5000,to);
	for(int i=1;i<=d+1;i++) add(3000+i,to,to);
}
signed main()
{
	cin>>d>>mod;
	init(); init2();
	getsqr(1,3);
	mulval(3,mod-1,4);
	getsqr(2,5);
	mulval(5,mod-1,6);
	add(1,2,7);
	getsqr(7,8);
	add(8,4,8),add(8,6,8);
	mulval(8,Inv(2),9);
	cout<<"f 9";
	return 0;
}