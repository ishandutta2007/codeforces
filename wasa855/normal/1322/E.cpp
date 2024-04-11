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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 500005
int a[N],mn[N][20],mx[N][20],lg[N],Ans[N],n;
pii query(int l,int r)
{
	int t=lg[r-l+1];
	return mp(min(mn[l][t],mn[r-(1<<t)+1][t]),max(mx[l][t],mx[r-(1<<t)+1][t]));
}
signed main()
{
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	a[0]=a[1],a[n+1]=a[n];
	for(int i=0;i<=n;i++) mn[i][0]=max(a[i],a[i+1]);
	for(int i=0;i<=n;i++) mx[i][0]=min(a[i],a[i+1]);
	// for(int i=0;i<=n;i++) printf("%d%c",mn[i][0]," \n"[i==n]);
	// for(int i=0;i<=n;i++) printf("%d%c",mx[i][0]," \n"[i==n]);
	for(int i=1;i<=19;i++) for(int j=0;j+(1<<i)-1<=n;j++) mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=19;i++) for(int j=0;j+(1<<i)-1<=n;j++) mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]||a[i]==a[i+1])
		{
			Ans[i]=a[i];
			continue;
		}
		int l=1,r=min(i,n-i+1),ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			auto [A,B]=query(i-mid,i+mid-1);
			if(B<A) ans=mid,l=mid+1;
			else r=mid-1;
		}
		maxn=max(maxn,ans);
		auto [A,B]=query(i-ans,i+ans-1);
		if((ans%2==0)==(a[i]>a[i-1])) Ans[i]=A;
		else Ans[i]=B;
	}
	cout<<maxn<<endl;
	for(int i=1;i<=n;i++) printf("%d%c",Ans[i]," \n"[i==n]);
	return 0;
}