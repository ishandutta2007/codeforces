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
int a[N],cnt[N],n,k;
void work()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	int ned=(n-k+1)/2+k;
	int L=0,R=0,v=inf;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		while(cur<=n&&cnt[cur]-cnt[i-1]<ned) cur++;
		if(cur>n) break;
		if(cur-i<v) v=cur-i,L=i,R=cur;
	}
	printf("%d %d\n",L,R);
	int las=0; cur=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=L&&a[i]<=R) cur++;
		else cur--;
		if(cur==1&&k>1) printf("%d %d\n",las+1,i),las=i,cur=0,k--;
	}
	printf("%d %d\n",las+1,n);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}