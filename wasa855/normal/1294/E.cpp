#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
vector<int> a[N];
int cnt[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) a[i].pb(read()-1);
	}
	int ans=0;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++) cnt[i]=0;
		for(int i=0;i<n;i++)
		{
			if(a[i][j]%m==j&&a[i][j]<n*m) cnt[(a[i][j]/m-i+n)%n]++;
		}
		int minn=N*10;
		for(int i=0;i<n;i++)
		{
			if(n-cnt[i]+(n-i)%n<minn) minn=n-cnt[i]+(n-i)%n;
		}
		ans+=minn;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}