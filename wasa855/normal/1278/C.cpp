#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
int a[N],sum[N];
map<int,int> mp;
void work()
{
	mp.clear();
	int n=read();
	for(int i=1;i<=2*n;i++) a[i]=read();
	for(int i=1;i<=2*n;i++)
	{
		if(a[i]==1) a[i]=-1;
		else a[i]=1;
	}
	int ans=0;
	for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
	int cur=0;
	for(int i=2*n;i>=n+1;i--)
	{
		cur+=a[i];
		mp[cur]=2*n-i+1;
		if(cur==0) ans=max(ans,2*n-i+1);
	}
	for(int i=n;i>=1;i--)
	{
		if(mp[-sum[i]]!=0) ans=max(ans,mp[-sum[i]]+i);
		if(sum[i]==0) ans=max(ans,i);
		cur+=a[i];
	}
	cout<<n*2-ans<<endl;
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