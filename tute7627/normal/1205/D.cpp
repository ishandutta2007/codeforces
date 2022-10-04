//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
struct edge{
  ll to=-1,cost=0;
  edge(){};
  edge(ll t,ll c):to(t),cost(c){};
};
struct CentroidDecomposition{
	ll n;
	const vector<vector<edge>> &g;
	vector<bool> used;//
	vector<ll> sub;//
	CentroidDecomposition(const vector<vector<edge>> &g):g(g){
		n = g.size();
		sub.assign(g.size(), 0);
		used.assign(g.size(), false);
	}
	ll search_centroid(ll root){
		return dfs_search(root, -1, dfs_sz(root, -1) / 2 );
	}
	ll dfs_sz(ll k, ll par){
		sub[k] = 1;
		for(auto e:g[k]){
			if(e.to == par || used[e.to])continue;
			sub[k] += dfs_sz(e.to, k);
		}
		return sub[k];
	}
	ll dfs_search(ll k, ll par, ll mid){
		for(auto e:g[k]){
			if(e.to == par || used[e.to])continue;
			if(sub[e.to] > mid)return dfs_search(e.to, k, mid);
		}
		return k;
	}
	vector<ll> centroid_enum(ll root){
    vector<ll>ret;
    ret.push_back(search_centroid(root));
    for(auto e:g[ret[0]]){
      if(used[e.to] || n != 2 * sub[e.to])continue;
      ll c = search_centroid(e.to);
      if(c != ret[0]){
        ret.push_back(c);
        break;
      }
    }
    return ret;
  }
  vector<vector<ll>>belong;
  vector<ll>pr;
  void build_all(){
    belong.resize(n);pr.resize(n);
    build(0,0);
  }
  void build(ll root,ll num){
    ll cent = search_centroid(root);
    used[cent] = true;
    pr[cent]=num;
    build_dfs(cent, -1, cent);
    for(auto e:g[cent])if(!used[e.to])build(e.to,num+1);
    used[cent] = false;
  }
  void build_dfs(ll k,ll par,ll cent){
    belong[k].push_back(cent);
    for(auto e:g[k]){
      if(e.to == par || used[e.to])continue;
      build_dfs(e.to, k, cent);
    }
  }
	void run(){
		//

		solve(0);
	}

	void solve(ll root){
		ll cent = search_centroid(root);
		ll size = sub[root];
		used[cent] = true;
		vector<vector<ll>>ver;
		for(auto e:g[cent]){
			if(!used[e.to]){
				ver.emplace_back();
				dfs(e.to,-1,ver.back());
			}
		}

		for(auto e:g[cent]){
			if(!used[e.to]){
				solve(e.to);
			}
		}
		used[cent] = false;

		return;
	}
	void dfs(ll k,ll par,vector<ll>&ver){
		ver.push_back(k);
		for(auto e:g[k]){
			if(e.to==par||used[e.to])continue;
			dfs(e.to,k,ver);
		}
	}
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<vector<edge>>g(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].EB(v,0);
    g[v].EB(u,0);
  }
  CentroidDecomposition cd(g);
  auto cent=cd.centroid_enum(0);
  ll c=cent[0];
  {

    const ll sz=1002;
    //const ll sz=10;cout<<"naosu"<<endl;
    vector<bitset<sz>>b(1);
    b[0]=1;
    vector<ll>s;
    vector<ll>v;
    rep(i,0,g[c].size()){
      auto dfs=[&](auto &&f,ll k,ll par)->ll{
        ll ret=1;
        for(auto e:g[k]){
          if(e.to==par)continue;
          ret+=f(f,e.to,k);
        }
        return ret;
      };
      s.PB(dfs(dfs,g[c][i].to,c));
      b.PB(b[i]|(b[i]<<s[i]));
      v.PB(g[c][i].to);
    }
    //debug(v,v.size());
    ll now=0;
    ll m=v.size();
    vector<vector<ll>>a(2);
    rrep(i,0,n/2+1)if(b[m][i]){now=i;break;}
    //debug(b,m+1);
    //cout<<now spa (n-1)/2 spa m spa c<<endl;
    //debug(s,m);
    rrep(i,0,m){
      if(b[i][now])a[0].PB(i);
      else{
        a[1].PB(i);
        now-=s[i];
      }
    }
    ll as=0;
    for(auto z:a[0])as+=s[z];
    map<P,ll>mp;
    rep(i,0,2){
      ll sum=0;
      ll mul=1;
      if(i)mul=as+1;
      ll time=0;
      for(auto z:a[i]){
        //cout<<i spa c spa z<<endl;
        time++;
        mp[MP(c+1,v[z]+1)]=time*mul;
        auto dfs=[&](auto &&f,ll k,ll par)->void{
          ll in=time;
          for(auto e:g[k]){
            if(e.to==par)continue;
            time++;
            mp[MP(k+1,e.to+1)]=(time-in)*mul;
            f(f,e.to,k);
          }
        };
        dfs(dfs,v[z],c);
      }
    }
    for(auto z:mp)cout<<z<<endl;
  }
  return 0;
}