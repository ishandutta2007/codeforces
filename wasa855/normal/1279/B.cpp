#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int a[N];
void work()
{
	int n,s;
	cin>>n>>s;
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	int maxx=0;
	if(sum<=s)
	{
		cout<<"0\n";
		return ;
	}
	sum=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[maxx]) maxx=i;
		sum+=a[i];
//		cout<<sum<<endl;
		if(sum-a[maxx]<=s) ans=maxx;
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}