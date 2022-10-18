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
#define N 1000005
int a[N],b[N],ans[N];
signed main()
{
	int n=read(),m=read(),sum=0;
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		sum+=a[i];
		b[i]=sum%n;
	}
	cout<<(sum+n-1)/n<<endl;
	b[m]=n;
	sort(b+1,b+m+1);
	for(int i=m;i>=1;i--) b[i]-=b[i-1];
	for(int i=1;i<=m;i++) printf("%d%c",b[i]," \n"[i==m]);
	int j=0; b[0]=b[m];
	for(int i=1;i<N;i++) ans[i]=1;
	for(int i=1;i<=m;i++)
	{
		// cout<<i<<endl;
		while(a[i]>0)
		{
			j++;
			a[i]-=b[j%m];
			ans[j]=i;
		}
	}
	for(int i=1;i<=(sum+n-1)/n*m;i++) printf("%d%c",ans[i]==0?1:ans[i]," \n"[i%m==0]);
	return 0;
}