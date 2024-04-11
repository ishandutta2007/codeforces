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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 5005
int x[N],y[N],ans[N];
int get(int x1,int y1,int x2,int y2) {return x1*x2+y1*y2;}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	ans[1]=1,ans[2]=2;
	for(int i=3;i<=n;i++)
	{
		ans[i]=i; int j=i;
		while(j>=3&&get(x[ans[j]]-x[ans[j-1]],y[ans[j]]-y[ans[j-1]],x[ans[j-2]]-x[ans[j-1]],y[ans[j-2]]-y[ans[j-1]])<=0) swap(ans[j],ans[j-1]),j--;
	}
	for(int i=2;i<n;i++)
	{
		if(get(x[ans[i-1]]-x[ans[i]],y[ans[i-1]]-y[ans[i]],x[ans[i+1]]-x[ans[i]],y[ans[i+1]]-y[ans[i]])<=0)
		{
			cout<<i<<endl;
			for(int k=i-5;k<=i+5;k++) printf("%d %d\n",x[k],y[k]);
			return 0;
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}