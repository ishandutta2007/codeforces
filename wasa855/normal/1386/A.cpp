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
typedef pair<int,int> pii;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int n,las=0;
int Query(int x)
{
	cout<<"? "<<x<<endl;
	return read();
}
void Guess()
{
	n=read(),las=0;
	vector<int> v;
	int l=1,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)/2; v.pb(mid);
		l=mid+1;
	}
	int cur=n,d=-1;
//	print(v);
	for(int i=v.size()-1;i>=0;i--,d*=-1) cur+=d*v[i];
	l=1,r=n-1; int ans=n;
	Query(cur);
//	cout<<cur<<endl;
	while(l<=r)
	{
		int mid=(l+r)/2;
		cur+=d*mid;
//		cout<<cur<<endl;
		if(Query(cur)) ans=mid,r=mid-1;
		else l=mid+1;
		d=-d;
	}
	cout<<"= "<<ans<<endl;
	// return ans;
}
signed main()
{
	int T=read(); while(T--) Guess();
}