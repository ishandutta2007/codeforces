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
int lowbit(int x){return x&(-x);}
struct BIT
{
	int t[N+5];
	void add(int u,int d)
	{
		while(u<=N) t[u]+=d,u+=lowbit(u);
	}
	int query(int u)
	{
		int ans=0;
		while(u) ans+=t[u],u-=lowbit(u);
		return ans;
	}
};
BIT bit;
int a[N],ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) bit.add(i+1,i);
	for(int i=n;i>=1;i--)
	{
		int l=1,r=n,mid,res;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(bit.query(mid)<=a[i]) l=mid+1,res=mid;
			else r=mid-1;
		}
		ans[i]=res;
		bit.add(ans[i]+1,-ans[i]);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}