#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
struct Node
{
	int l,r;
};
int n,s;
Node a[N];
int _l[N],_r[N];
int rl[N];
bool judge(int x)
{
	int upp=0,low=0,ans=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].l>x) ans+=a[i].l,upp++;
		else if(a[i].r<x) ans+=a[i].l,low++;
		else rl[++cnt]=a[i].l;
	}
	sort(rl+1,rl+cnt+1);
	for(int i=low+1;i<=n/2;i++) ans+=rl[i-low];
	ans+=x*(n/2+1-upp);
	return ans<=s;
}
void work()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++) _l[i]=a[i].l=read(),_r[i]=a[i].r=read();
	sort(_l+1,_l+n+1);
	sort(_r+1,_r+n+1);
	int l=_l[n/2+1],r=_r[n/2+1],mid,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid)) ans=mid,l=mid+1;
		else r=mid-1;
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