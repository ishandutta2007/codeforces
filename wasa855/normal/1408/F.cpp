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
vector<int> v[20];
vector<pii> ans;
void print1(int b,int l)
{
	for(int i=1;i<l;i<<=1)
	{
		for(int j=0;j<l;j+=i*2)
		{
			for(int k=1;k<=i;k++) ans.eb(b+j+k,b+i+j+k);
		}
	}
}
vector<int> merge(vector<int> x,vector<int> y)
{
	for(int i=0;i<(int)x.size();i++) ans.eb(x[i],y[i]);
	vector<int> ans=x; for(int i:y) ans.pb(i);
	return ans;
}
signed main()
{
	int n=read(),cnt=0;
	vector<int> h;
	for(int i=0;i<=16;i++)
	{
		if(n>>i&1)
		{
			print1(cnt,1<<i);
			for(int j=1;j<=1<<i;j++) v[i].pb(cnt+j);
			cnt+=1<<i;
			h.pb(i);
		}
	}
	reverse(h.begin(),h.end());
	while(h.size()>2)
	{
		int r=h.back(),ned=1<<r;
		h.pop_back();
		vector<int> tmp;
		for(int i=1;i<=ned;i++)
		{
			tmp.pb(v[h[0]].back());
			v[h[0]].pop_back();
		}
//		cout<<r<<endl;
		v[r]=merge(tmp,v[r]);
		while(h.size()!=1&&h.back()==r+1)
		{
			v[r+1]=merge(v[r+1],v[r]);
			r++;
			h.pop_back();
//			printf("%d %d\n",r,h.back());
		}
		h.pb(r+1);
		v[r+1]=v[r];
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
	return 0;
}