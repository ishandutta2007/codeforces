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
#define N 200005
int a[N];
pii query(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int x=read(),y=read();
	return mp(x,y);
}
void solve(int l,int r)
{
	if(l>r) return ;
	auto [x,y]=query(l,r);
	int L=r-y+1,R=l+y-1;
	if(L<=R)
	{
		for(int i=L;i<=R;i++) a[i]=x;
		solve(l,L-1),solve(R+1,r);
	}
	else
	{
		int mid=(l+r)/2;
		solve(l,mid),solve(mid+1,r);
	}
}
signed main()
{
	int n=read();
	solve(1,n);
	cout<<"! ";
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<endl;
	return 0;
}