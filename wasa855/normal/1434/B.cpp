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
int ans[N],n;
int opt[N],v[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		char ch; cin>>ch; opt[i]=ch=='+';
		if(!opt[i]) v[i]=read();
	}
	stack<int> st; set<int> s;
	for(int i=1;i<=n*2;i++)
	{
		if(opt[i]) s.insert(i);
		else
		{
			while(!st.empty()&&v[st.top()]<v[i]) st.pop();
			int p=st.empty()?0:st.top(); st.push(i);
			auto pos=s.lower_bound(p);
			if(pos==s.end()) {cout<<"NO\n"; return 0;}
			ans[*pos]=v[i];
			s.erase(pos);
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n*2;i++) if(opt[i]) printf("%d ",ans[i]);
	return 0;
}