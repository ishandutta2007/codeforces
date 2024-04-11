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
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int u=read();
		a[u]=i;
	}
	int ans=0,las=0;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		if(a[x]<=las) ans++;
		else
		{
			ans+=2*(a[x]-i)+1;
			las=a[x];
		}
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