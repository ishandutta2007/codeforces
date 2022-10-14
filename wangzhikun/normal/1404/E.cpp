#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

const int inf = 1e9;

struct way{
	int to,flow,rev;
};

const int N = 44040;
struct dinic{
	vector<way> ways[N];
	int n,m,s,t,u,v,f,ans = 0,cuad,cur,cpo[N];
	int depth[N] = {0};
	queue<int> que;
	dinic(){
		s = N-1;
		t = N-2;
	}
	bool bfs(){
		memset(depth,0,sizeof(depth));
		depth[s] = 1;
		que.push(s);
		while(!que.empty()){
			cur = que.front(); que.pop();
			for(auto ech:ways[cur])
				if(!depth[ech.to]&&ech.flow>0){
					depth[ech.to] = depth[cur]+1;
					que.push(ech.to);
				}
		}
		return depth[t]!=0;
	}
	int dfs(int num,int flow){
		if(num == t) return flow;
		int cacu = 0;
		for(int &i=cpo[num];i<ways[num].size();i++){
			way cw = ways[num][i];
			if(depth[cw.to]!=depth[num]+1)continue;
			int able = dfs(cw.to,min(flow,cw.flow));
			if(able>0){
				flow-=able;
				ways[num][i].flow-=able;
				ways[cw.to][cw.rev].flow+=able;
				cacu+=able;
			}
			if(flow == 0)break;
		}
		return cacu;
	}
	void addedge(int u,int v,int f){
		ways[u].push_back((way){v,f,(int)ways[v].size()});
		ways[v].push_back((way){u,0,(int)ways[u].size()-1});
	}
	int getans(){
		while(bfs()){
			memset(cpo,0,sizeof(cpo));
			while(1){
				cuad = dfs(s,inf);
				if(cuad == 0)break;
				ans+=cuad;
			}
		}
		return ans;
	}
};

const int S = N-5,T = N-10;
char cmp[220][220];
int d[4][2] = {0,1,0,-1,-1,0,1,0};
int main(){
	dinic A;
	A.s = S;
	A.t = T;
	int u,v,f;
	int n,m;
	read(n,m);
	for(int i=1;i<=n;i++)cin>>(cmp[i]+1);
	int cans = 0,ccc =0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cmp[i][j]!='#')continue;
			ccc+=1;
			int dd[2] = {0};
			for(int k=0;k<4;k++){
				int ni = i+d[k][0],nj = j+d[k][1];
				if(cmp[ni][nj]!='#')continue;
				cans+=1;
				dd[k/2]+=1;
				if(k<2)A.addedge(i*200+j,ni*200+nj,1);
				else A.addedge(ni*200+nj,i*200+j,1);
			}
			A.addedge(S,i*200+j,dd[0]);
			A.addedge(i*200+j,T,dd[1]);
		}
	}
	cout<<ccc-(cans-A.getans())/2<<endl;
	return 0;
}