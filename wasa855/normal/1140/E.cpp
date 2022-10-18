#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int a[N];
int b[N];
int f[N][2];
int k;
int work(int a[],int n)
{
	if(n==0) return 1;
	int l=0,r=n-1;
	while(a[l]==-1&&l<n) l++;
	if(l==n) return k*qpow(k-1,n-1)%mod;
	while(a[r]==-1) r--;
	int ans=qpow(k-1,l)*qpow(k-1,n-r-1)%mod;
	int las=l;
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]==-1) continue;
		ans=ans*f[i-las-1][a[las]==a[i]]%mod;
		las=i;
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n>>k;
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1) a[ca++]=read();
		else b[cb++]=read();
	}
	f[0][1]=0,f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=(k-1)*f[i-1][0]%mod;
		f[i][0]=(f[i-1][1]+(k-2)*f[i-1][0])%mod;
	}
	cout<<(work(a,(n+1)/2)*work(b,n/2)%mod)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}