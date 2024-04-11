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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 400005
int a[N],b[N],fl[N],fr[N],id[N],pre[N],n,m,k;
void work()
{
	m=read(),n=read(),k=read()+n+1;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	b[++n]=m-a[n];
	int l=1,r=m,L;
	for(int i=1;i<=n;i++) r=min(r,b[i]);
	while(l<=r)
	{
		int mid=(l+r)/2,sum=0;
		for(int j=1;j<=n;j++) sum+=b[j]/mid;
		if(sum>=k) L=mid,l=mid+1;
		else r=mid-1;
	}
	l=1,r=m; int R;
	while(l<=r)
	{
		int mid=(l+r)/2,sum=0;
		for(int j=1;j<=n;j++) sum+=(b[j]+mid-1)/mid;
		if(sum<=k) R=mid,r=mid-1;
		else l=mid+1;
	}
	// printf("%lld %lld\n",L,R);
	for(int i=1;i<=n;i++)
	{
		int t=(b[i]+R-1)/R; fl[i]=min(L,b[i]/t);
		t=b[i]/L; fr[i]=max(R,(b[i]+t-1)/t);
	}
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return fl[x]<fl[y];});
	pre[0]=R; for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],fr[id[i]]);
	int ans=pre[n]-L;
	for(int i=1;i<=n;i++) ans=min(ans,pre[i-1]-fl[id[i]]);
	printf("%lld\n",ans);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}