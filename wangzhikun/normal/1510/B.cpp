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

template<typename T> void read01(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*2+ch-48;ch=getchar();}x*=f;
}

template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

const int N = 2500;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int d,n,a,vis[1040];

struct cost{
    int m,n,s,t,u,v,ca,co;
    ll dist[N],inq[N],prv[N],pre[N];
    int rel[N][N];
    struct edge{int to,ca,cost,rev;};
    vector<edge> G[N];
    void addedge(int u,int v,int co,int ca){
        G[u].push_back((edge){v,ca,co,(int)G[v].size()});
        G[v].push_back((edge){u,0,-co,(int)G[u].size()-1});
    }
    int mf;
    int getans(){
        mf = 0;
        ll mm = 0;
        while(1){
            queue<int> que;
            memset(dist, inf , sizeof(dist));
            memset(inq,0,sizeof(inq));
            dist[s] = 0;
            que.push(s);
            inq[s] = 1;
            while(!que.empty()){
                int cur = que.front();
                que.pop();
                inq[cur] = 0;
                for(int i=0;i<G[cur].size();i++){
                    edge cw = G[cur][i];
                    if(cw.ca<=0)continue;
                    if(dist[cw.to]>cw.cost+dist[cur]){
                        dist[cw.to] = cw.cost+dist[cur];
                        prv[cw.to] = cur;
                        pre[cw.to] = i;
                        if(!inq[cw.to]){
                            que.push(cw.to);
                            inq[cw.to] = 1;
                        }
                    }
                }
            }
            if(dist[t]==inf)break;
            ll md = inf,di = 0;
            for(int p = t;p!=s;p = prv[p]){
                edge & cedge = G[prv[p]][pre[p]];
                md = min(md,(ll)cedge.ca);
                di += cedge.cost;
            }

            for(int p = t;p!=s;p = prv[p]){
                rel[prv[p]][p]+=md;
                rel[p][prv[p]]-=md;
            }
            if(di>0)break;
            mm+=di*md;
            mf+=md;
            for(int p = t;p!=s;p = prv[p]){
                edge & cedge = G[prv[p]][pre[p]];
                cedge.ca-=md;
                G[cedge.to][cedge.rev].ca+=md;
            }
        }
        //debug(mm);
        return mm;
    }
    string ans;
    void dfs(int c){
        //debug(c);
        if(c == t)return;
        for(auto ct:G[c]){
            if(rel[c][ct.to]>0){
                rel[c][ct.to]-=1;
                if(c>=1100 && ct.to<1100){
                    for(int j=0;j<10;j++){
                        if(c-1100+(1<<j) == ct.to){
                            ans+=('0'+d-1-j);
                        }
                    }
                }
                dfs(ct.to);
                return;
            }
        }
        cout<<"Panik"<<endl;
    }
    void getansstr(){
        for(int i=0;i<mf;i++){
            dfs(0);
            if(i<mf-1)ans+="R";
        }
        cout<<ans.length()<<endl;
        for(int i=0;i<ans.length();i++){
            cout<<ans[i]<<" \n"[i == ans.length()-1];
        }
    }
} FLOW;

int main() {
    read(d,n);
    for(int i=0;i<n;i++){
        read01(a);
        vis[a] = 1;
    }
    FLOW.s = 0;
    FLOW.t = 2400;
    for(int i=0;i<1<<d;i++){
        for(int j=0;j<d;j++){
            if((i&(1<<j)) == 0){
                FLOW.addedge(i+1100,i+(1<<j),1,1000000);
            }
        }
        FLOW.addedge(i,i+1100,0,1000000);
        if(vis[i]) FLOW.addedge(i,i+1100,-10000000,1);
        FLOW.addedge(i+1100,2400,1,1000000);
    }
    FLOW.getans();
    FLOW.getansstr();
    return 0;
}