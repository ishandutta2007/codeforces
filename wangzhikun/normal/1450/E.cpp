/*
    Author: Zhikun Wang 
 */
 
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
typedef vector<int> vi;

template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int n,m;

vi G1[200020],G2[200020];

int vis[200020],col[200020],ok = 1;

void color(int num){
	vis[num] = 1;
	for(auto ct:G1[num]){
		if(vis[ct] && col[ct] == col[num])ok = 0;
		if(!vis[ct]){
			col[ct] = col[num]^1;
			color(ct);
		}
	}
	for(auto ct:G2[num]){
		if(vis[ct] && col[ct] == col[num])ok = 0;
		if(!vis[ct]){
			col[ct] = col[num]^1;
			color(ct);
		}
	}
}

int dis[220];
int main() {
    read(n,m);
    for(int i=0;i<m;i++){
    	int u,v,w;
    	read(u,v,w);
    	if(!w){
    		G1[u].PB(v);
    		G1[v].PB(u);
    	}else{
    		G1[u].PB(v);
    		G2[v].PB(u);
    	}
    }
    color(1);
    if(!ok){
    	cout<<"NO\n";
    	return 0;
    }
    int ans = -1e9,as[220];
    for(int cid=1;cid<=n;cid++){
    	memset(dis,7,sizeof(dis));
    	dis[cid] = 0;
    	for(int i=1;i<=n+10;i++){
    		int cng = 0;
    		for(int j=1;j<=n;j++){
    			for(auto ct:G1[j]){
    				if(dis[ct]>dis[j]+1){
    					cng = 1;
    					dis[ct] = dis[j]+1;
    				}
    			}

    			for(auto ct:G2[j]){
    				if(dis[ct]>dis[j]-1){
    					cng = 1;
    					dis[ct] = dis[j]-1;
    				}
    			}
    		}
    		if(!cng)break;
    		if(cng && i>n){
    			cout<<"NO\n";
    			return 0;
    		}
    	}
    	int cmx = -1e9,cmi = 1e9;
    	for(int i=1;i<=n;i++){
    		cmx = max(cmx,dis[i]);
    		cmi = min(cmi,dis[i]);
    	}
    	if(cmi>=0 && cmx>ans && cmx<300){
    		ans = cmx;
    		memcpy(as,dis,sizeof(as));
    	}
    }
    cout<<"YES\n";
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)cout<<as[i]<<" \n"[i == n];
    return 0;
}