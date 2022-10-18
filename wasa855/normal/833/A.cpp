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
int get(int b)
{
	int l=1,r=1000000,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*mid*mid>=b) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans*ans*ans==b) return ans;
	else return -1;
}
void work()
{
	int a=read(),b=read();
	int v=get(a*b);
	if(v==-1) cout<<"No\n";
	else
	{
		auto chk=[&](int v)
		{
			int c1=0,c2=0;
			int ta=a,tb=b;
			while(ta%v==0) c1++,ta/=v;
			while(tb%v==0) c2++,tb/=v;
			if(c1>c2) swap(c1,c2);
			return c1*2>=c2;
		};
		int ans=1;
		for(int i=2;i*i<=v;i++)
		{
			if(v%i==0)
			{
				ans&=chk(i);
				while(v%i==0) v/=i;
			}
		}
		if(v!=1) ans&=chk(v);
		if(ans) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}