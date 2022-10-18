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
#define N 100005
int a[N],n;
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}bit;
void work()
{
	int x=0,y=0;
	n=read(); for(int i=1;i<=n;i++) a[i]=read()&1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1) y++;
		else x++;
	}
	if(abs(x-y)>=2) {cout<<"-1\n"; return ;}
	if(n%2==0)
	{
		int ans1=0,ans2=0,cnt1=1,cnt2=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1) ans1+=abs(i-cnt1),cnt1+=2;
			else ans1+=abs(i-cnt2),cnt2+=2;
		}
		cnt1=2,cnt2=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1) ans2+=abs(i-cnt1),cnt1+=2;
			else ans2+=abs(i-cnt2),cnt2+=2;
		}
		cout<<min(ans1,ans2)/2<<endl;
	}
	else
	{
		int cnt1,cnt2,ans1=0;
		if(x>y) cnt1=2,cnt2=1;
		else cnt1=1,cnt2=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1) ans1+=abs(i-cnt1),cnt1+=2;
			else ans1+=abs(i-cnt2),cnt2+=2;
			// printf("%d %d - %d\n",cnt1,cnt2,ans1);
		}
		cout<<ans1/2<<endl;
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}