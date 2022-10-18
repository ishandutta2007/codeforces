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
#define N 500005
int a[N];
set<int> s;
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	s.clear();
	int x=1,y=0,l=1,r=inf,ans=1;
	for(int i=1;i<=n;i++)
	{
		x*=-1,y=a[i]-y;
		int tl=l,tr=r;
		l=max(a[i]-tr,1LL);
		r=min(a[i]-1,a[i]-tl);
		// printf("%d %d %d %d\n",x,y,l,r);
		int qaq=ans+1;
		if(a[i]%2==0)
		{
			if(((l<=a[i]/2)&&(a[i]/2<=r))||s.find((a[i]/2-y)*x)!=s.end())
			{
				qaq=ans,l=1,r=0;
				x=1,y=0; s.clear();
				s.insert(a[i]/2);
			}
			else
			{
				s.insert((a[i]/2-y)*x);
			}
		}
		while(!s.empty()&&*s.begin()*x+y<=0) s.erase(s.begin());
		while(!s.empty()&&*s.begin()*x+y>=a[i]) s.erase(s.begin());
		while(!s.empty()&&*s.rbegin()*x+y<=0) s.erase(*s.rbegin());
		while(!s.empty()&&*s.rbegin()*x+y>=a[i]) s.erase(*s.rbegin());
		ans=qaq;
		if(s.empty()&&l>r)
		{
			l=1,r=a[i]-1;
			ans++;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}