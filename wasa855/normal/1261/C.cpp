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
#define N 1000005
vector<int> a[N];
vector<int> sum[N];
vector<int> res[N],r[N];
char s[N];
int n,m;
int get(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1];
}
bool judge(int mid)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) res[i][j]=r[i][j]=0;
	}
	mid=mid+mid+1;
	for(int i=1;i+mid-1<=n;i++)
	{
		for(int j=1;j+mid-1<=m;j++)
		{
			int re=get(i,j,i+mid-1,j+mid-1);
			if(re!=mid*mid) continue;
			res[i+mid/2][j+mid/2]=1;
			r[i][j]++,r[i+mid][j]--,r[i][j+mid]--,r[i+mid][j+mid]++;
		}
	}
//	cout<<"Passed\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			r[i][j]+=r[i-1][j]+r[i][j-1]-r[i-1][j-1];
			if(a[i][j]==1&&r[i][j]==0) return false;
		}
	}
	return true;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=0;i<=m;i++) a[0].pb(0);
	for(int i=0;i<=m;i++) sum[0].pb(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		a[i].pb(0);
		for(int j=1;j<=m;j++) a[i].pb(s[j]=='X');
	}
	for(int i=1;i<=n;i++)
	{
		sum[i].pb(0);
		for(int j=1;j<=m;j++)
		{
			sum[i].pb(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]);
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++) res[i].pb(0),r[i].pb(0);
	}
	int l=0,r=n*m,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
//	cout<<"Passed\n";
	judge(ans);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%c",res[i][j]==1?'X':'.');
		}
		printf("\n");
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}