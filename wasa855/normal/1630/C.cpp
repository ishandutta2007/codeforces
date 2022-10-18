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
int s[N],a[N],l[N],r[N],po[N],n;
int st[N][20],lg[N];
int Max(int x,int y) {return po[x]>po[y]?x:y;}
int qry(int l,int r)
{
	int t=lg[r-l+1];
	return Max(st[l][t],st[r-(1<<t)+1][t]);
}
signed main()
{
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	cin>>n; for(int i=1;i<=n;i++) l[i]=inf;
	for(int i=1;i<=n;i++) a[i]=read(),l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	for(int i=1;i<=n;i++) if(l[i]<r[i]) s[l[i]+1]++,s[r[i]]--,po[l[i]]=r[i];
	for(int i=1;i<=n;i++) st[i][0]=i;
	for(int i=1;i<=19;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[j][i]=Max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!po[i]) continue;
		int cl=i,cr=po[i];
		ans+=cr-cl-1; int fl=0;
		while(1)
		{
			int tr=qry(cl,cr);
			if(!po[tr]||po[tr]<=cr) break;
			cl=cr,cr=po[tr];
			ans+=cr-cl-1;
			fl=1;
		}
		// if(fl) ans--;
		i=cr;
	}
	cout<<ans<<endl;
	return 0;
}