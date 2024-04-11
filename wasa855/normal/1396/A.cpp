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
#define mod 998244353
#define int long long
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
#define N 100005
int rev[N],a[N];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1)
	{
		cout<<"1 1\n";
		cout<<-a[1]<<endl;
		cout<<"1 1\n";
		cout<<0<<endl;
		cout<<"1 1\n";
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++) rev[i*(n-1)%n]=i;
	printf("%d %lld\n",1,n-1);
	for(int i=1;i<n;i++)
	{
		int r=rev[((n-a[i]%n)+n)%n];
		printf("%lld ",r*(n-1));
		a[i]+=r*(n-1);
	}
	cout<<"\n";
	printf("%lld %lld\n",n,n);
	cout<<-a[n]<<endl; a[n]=0;
	printf("%d %lld\n",1,n);
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",-a[i]);
	}
	cout<<"\n";
	return 0;
}