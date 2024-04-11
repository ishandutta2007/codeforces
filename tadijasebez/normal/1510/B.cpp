
// Problem: B. Button Lock
// Contest: Codeforces - 2020-2021 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1510/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=1024*2+2;
int source=N-2,sink=N-1;
struct edge{
	int nxt,cap,w,rev,beg;
};
vector<vector<edge>> graf(N);
void addEdge(int u,int v,int c,int w){ //u->v, capacity, cost
	edge a={v,c,w,graf[v].size(),c},b={u,0,-w,graf[u].size(),0};
	graf[u].pb(a);
	graf[v].pb(b);
}
int flw;
int spfa(){
	vector<bool> in(N);
	vector<int> dist(N,INT_MAX),par(N);
	queue<int> q;
	q.push(source);
	dist[source]=0;
	par[source]=source;
	in[source]=1;
	while(q.size()){
		int tr=q.front();
		q.pop();
		in[tr]=0;
		for(auto p:graf[tr]){
			if(p.cap&&dist[tr]+p.w<dist[p.nxt]){
				dist[p.nxt]=dist[tr]+p.w;
				par[p.nxt]=p.rev;
				if(!in[p.nxt])
					in[p.nxt]=1,q.push(p.nxt);
			}
		}
	}
	if(dist[sink]==INT_MAX)
		return 0;
	int mn=INT_MAX;
	int tr=sink;
	while(tr!=source){
		int sl=graf[tr][par[tr]].nxt;
		mn=min(mn,graf[sl][graf[tr][par[tr]].rev].cap);
		tr=sl;
	}
	tr=sink;
	while(tr!=source){
		int sl=graf[tr][par[tr]].nxt;
		graf[tr][par[tr]].cap+=mn;
		graf[sl][graf[tr][par[tr]].rev].cap-=mn;
		tr=sl;
	}
	flw+=mn;
	return dist[sink];
}
int flow(){
	flw=0;
	int tr=0;
	while(int d=spfa())tr+=d;
	return tr;
}
int d,n;
int main()
{
	rd(d,n);
	vector<int> a(n),cnt(n);
	vector<string> ss(n);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		ss[i]=s;
		for(auto p:s)
			a[i]=2*a[i]+(p=='1'),cnt[i]+=p=='1';
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(i!=j&&(a[i]&a[j])==a[i]){
				addEdge(i,n+j,1,-cnt[i]);
			}
		}
	for(int i=0;i<n;i++)
		addEdge(source,i,1,0),addEdge(i+n,sink,1,0);
	flow();
	vector<int> ope;
	vector<bool> matched(2*n);
	vector<int> match(n,-1);
	for(auto p:graf[sink])
		if(p.beg!=p.cap)
			matched[p.nxt]=1;
	for(int i=0;i<n;i++){
		for(auto p:graf[i])
			if(p.nxt!=source&&p.beg!=p.cap)
				match[i]=p.nxt-n;
	}
	string start(d,'0');
	string tr=start;
	for(int i=0;i<n;i++){
		if(!matched[i+n]){
			if(tr!=start){
				ope.pb(-1);
				tr=start;
			}
			int trInd=i;
			for(int j=0;j<d;j++)
				if(tr[j]!=ss[trInd][j])
					ope.pb(j),assert(tr[j]=='0'),tr[j]='1';
			while(match[trInd]!=-1){
				trInd=match[trInd];
				for(int j=0;j<d;j++)
					if(tr[j]!=ss[trInd][j])
						ope.pb(j),assert(tr[j]=='0'),tr[j]='1';
			}
		}
	}
	printf("%i\n",ope.size());
	for(auto p:ope)
		if(p==-1)
			printf("R ");
		else
			printf("%i ",p);
	return 0;
}