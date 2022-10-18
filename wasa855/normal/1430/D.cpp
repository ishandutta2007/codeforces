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
#define N 200005
char s[N];
int n,a[N],nxt[N];
void work()
{
	cin>>n; scanf("%s",s+1);
	int ans=0; int m=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(s[j+1]==s[i]) j++;
		a[++m]=j-i+1;
		i=j;
	}
	nxt[m+1]=m+1;
	for(int i=m;i>=1;i--)
	{
		if(a[i]>=2) nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	// for(int i=1;i<=m;i++) printf("%d%c",a[i]," \n"[i==m]);
	int t=1;
	for(int i=1;i<=m;i++)
	{
		ans++;
		if(t!=m+1&&(a[t]==1||t<i)) t=nxt[t+1];
		// cout<<t<<endl;
		if(t!=m+1&&a[t]>=2) a[t]--;
		else i++;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}