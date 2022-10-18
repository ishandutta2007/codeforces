#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
int n,k,a[N],b[N];
struct Node
{
	int id,dat;
	Node(int id=0,int dat=0):id(id),dat(dat){};
};
Node c[N];
bool cmp(Node x,Node y)
{
	return x.dat>y.dat;
}
bool judge(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=a[i];
		while(l<=r)
		{
			int mid=(l+r)/2;
			int A=mid*(a[i]-mid*mid);
			int B=(mid-1)*(a[i]-(mid-1)*(mid-1));
			if(A-B>=x) l=mid+1;
			else r=mid-1;
		}
		b[i]=r,sum+=r;
	}
	return sum>=k;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	int l=-INF,r=INF;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid)) l=mid+1;
		else r=mid-1;
	}
	judge(r);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		if(!b[i]) continue;
		int A=b[i]*(a[i]-b[i]*b[i]);
		int B=(b[i]-1)*(a[i]-(b[i]-1)*(b[i]-1));
		c[++cnt]=Node(i,B-A);
	}
	sum-=k;
	sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=sum;i++) b[c[i].id]--;
	for(int i=1;i<=n;i++) printf("%lld ",b[i]);
	return 0;
}