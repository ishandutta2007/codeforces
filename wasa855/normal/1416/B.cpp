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
#define N 100005
int a[N];
void work()
{
	int n=read(); for(int i=1;i<=n;i++) a[i]=read();
	int sum=0; for(int i=1;i<=n;i++) sum+=a[i];
	if(sum%n!=0)
	{
		cout<<-1<<"\n";
		return ;
	}
	vector<vector<int>> ans;
	for(int i=2;i<=n;i++)
	{
		int go=(i-a[i]%i)%i;
		ans.pb({1,i,go});
		a[i]+=go,a[1]-=go;
		go=a[i]/i;
		ans.pb({i,1,go});
		a[1]+=a[i];
	}
	for(int i=2;i<=n;i++) ans.pb({1,i,sum/n});
	cout<<ans.size()<<endl;
	for(auto i:ans)
	{
		for(int j:i) printf("%d ",j);
		cout<<"\n";
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}