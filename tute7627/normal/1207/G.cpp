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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
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
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<long long iden, long long size>
struct Trie{
  struct Node{
    vector<ll>next,idx;
    ll num, failure, len;
    Node(ll l):num(0), failure(-1), len(l){
       next.assign(size,-1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back(0);
  }
  ll add(const string &s, ll id){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1){
        data[pos].next[c]=data.size();
        data.emplace_back(i+1);
      }
      data[pos].num++;
      pos = data[pos].next[c];
    }
    data[pos].num++;
    data[pos].idx.push_back(id);
		return pos;
  }
	ll append(ll pos,char cc){
		ll c = cc - iden;
		if(data[pos].next[c]==-1){
			data[pos].next[c]=data.size();
      data.emplace_back(0);
		}
		pos=data[pos].next[c];
		return pos;
	}
  void search(const string &s){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1)break;
      pos = data[pos].next[c];
    }
  }
  vector<ll>v;
  void dfs(ll pos, ll d){
    for(ll i=0;i<size;i++){
      if(data[pos].next[i]!=-1){
        dfs(data[pos].next[i], d+1);
      }
    }
  }
  vector<string>str;
  void build_str(ll pos=0,string s=""){
    while(str.size()<=pos)str.push_back("");
    str[pos]=s;
    for(ll i=0;i<size;i++){
      if(data[pos].next[i]!=-1){
        build_str(data[pos].next[i],s+char(i+iden));
      }
    }
  }
  void build_Ahocorasick(){
    queue<ll>que;
    que.push(0);
    data[0].failure = -1;
    while(!que.empty()){
      ll pos = que.front();
      for(ll i=0;i<size;i++){
        if(data[pos].next[i]==-1)continue;
        ll now = data[pos].failure;
        while(now!=-1&&data[now].next[i]==-1)now = data[now].failure;
        if(now==-1)data[data[pos].next[i]].failure = 0;
        else data[data[pos].next[i]].failure = data[now].next[i];
        que.push(data[pos].next[i]);
      }
      que.pop();
    }
  }
  vector<ll> aho_search(const string &s){
    ll now=0;
    vector<ll>cnt(data.size());
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      while(now!=-1&&data[now].next[c]==-1)now=data[now].failure;
      if(now==-1)now=0;
      else{
        now=data[now].next[c];
        ll pos=now;
        while(pos!=-1){
          cnt[pos]++;
          pos=data[pos].failure;
        }
      }
    }
    return cnt;
  }
};
template<typename T>
struct BIT{
  ll n;
  ll k=1;
  vector<T>data;
  BIT() = default;
  BIT(ll size):n(size){
    data.assign(n,0);
    while(k*2<=n)k*=2;
  }
  void add(ll a,T w){
    for(ll i=a+1;i<=n;i+=i&-i)data[i-1]+=w;
  }
  T sum(ll a){
	if(a<0)return 0;
    T ret = 0;
    for(ll i=a+1;i>0;i-=i&-i)ret+=data[i-1];
    return ret;
  }
  T sum(ll a,ll b){return a>b?0:sum(b)-sum(a-1);}
  T operator[](ll pos){
    return sum(pos,pos);
  }
  ll lower_bound(ll x){
    ll ret=0;    
    for(ll i=k;i>0;i/=2){
      if(ret+i<=n&&data[ret+i-1]<x){
        x-=data[ret+i-1];
        ret+=i;
      }
    }
    return ret;
  }
  void print(){
    for(ll i=0;i<n;i++){
      if(i!=0)cout<<" ";
      cout<<(*this)[i];
    }
    cout<<endl;
  }
};
using trie = Trie<'a',26>;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
	ll n;cin>>n;
	vector<ll>id(n);
	trie tri;
	rep(i,0,n){
		ll type;cin>>type;
		if(type==1){
			char c;cin>>c;
			id[i]=tri.append(0,c);
		}
		else{
			ll j;cin>>j;j--;
			char c;cin>>c;
			id[i]=tri.append(id[j],c);
		}
	}
	trie aho;
	ll m;cin>>m;
	ll szt=tri.data.size();
	vector<vector<P>>query(szt);
	rep(i,0,m){
		ll x;cin>>x;x--;
		string s;cin>>s;
		ll to=aho.add(s,i);
		query[id[x]].EB(i,to);
	}
	aho.build_Ahocorasick();
	ll sza=aho.data.size();
	vector<vector<ll>>g(sza);
	rep(i,1,sza){
		g[aho.data[i].failure].PB(i);
	}
	vector<ll>in(sza),out(sza);
	auto accept=vec(sza,26,0);
	{
		ll t=0;
		auto dfs=[&](auto &&f,ll pos,ll par)->void{
			if(par!=-1)accept[pos]=accept[par];
			rep(i,0,26){
				if(aho.data[pos].next[i]!=-1)accept[pos][i]=aho.data[pos].next[i];
			}
			in[pos]=t++;
			for(auto to:g[pos]){
				f(f,to,pos);
			}
			out[pos]=t-1;
		};
		dfs(dfs,0,-1);
	}
	//debug(accept,sza,26);
	vector<ll>ret(m);
	BIT<ll>bit(sza);
	{
		auto dfs=[&](auto &&f,ll pos,ll now,ll c)->void{
			auto &tr=tri.data[pos];
			if(c!=-1){
				now=accept[now][c];
			}
			bit.add(in[now],1);
			for(auto z:query[pos]){
				//bit.print();
				ret[z.fi]=bit.sum(in[z.se],out[z.se]);
			}
			rep(i,0,26){
				if(tr.next[i]==-1)continue;
				f(f,tr.next[i],now,i);
			}
			bit.add(in[now],-1);
		};
		dfs(dfs,0,0,-1);
	}
	rep(i,0,m)cout<<ret[i]<<endl;
  return 0;
}