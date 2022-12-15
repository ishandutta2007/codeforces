#include <bits/stdc++.h>
using namespace std;

#define int long long
#define len(x) ((int)(x).size())
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define backof(x) back_inserter(x)

#define eric574 copy
#define eric574_if copy_if

#define IN_PAIR template<class T1,class T2>istream& operator>>(istream& is,pair<T1,T2>& p)
#define OUT_PAIR template<class T1,class T2>ostream& operator<<(ostream& os,pair<T1,T2> p)
#define IN_TUPLE template<class...Ts>istream& operator>>(istream& is,tuple<Ts...>& t)
#define OUT_TUPLE template<class...Ts>ostream& operator<<(ostream& os,tuple<Ts...> t)
#define IN_ITER template<class T,class=decltype(begin(declval<T>())),class=decltype(end(declval<T>())),class=enable_if_t<!is_same_v<T,string>>>istream& operator>>(istream &is,T& a)
#define OUT_ITER template<class T,class=decltype(begin(declval<T>())),class=decltype(end(declval<T>())),class=enable_if_t<!is_same_v<T,string>>>ostream& operator<<(ostream &os,T a)

IN_PAIR;OUT_PAIR;IN_TUPLE;OUT_TUPLE;IN_ITER;OUT_ITER;

IN_PAIR{is>>p.first>>p.second;return is;}
OUT_PAIR{os<<p.first<<" "<<p.second;return os;}
IN_TUPLE{apply([&is](auto&...args){((is>>args),...);},t);return is;}
OUT_TUPLE{apply([&os](auto&...args){int __n=0;((os<<args<<(++__n!=sizeof...(Ts)?" ":"")),...);},t);return os;}
IN_ITER{for(auto it=begin(a);it!=end(a);it++)is>>*it;return is;}
OUT_ITER{for(auto it=begin(a);it!=end(a);it++)os<<(it==begin(a)?"":" ")<<*it;return os;}

void solve(){
	int n;cin>>n;
	vector<int> p(n);cin>>p;
	// fwd[i]: number of j where i << j and pi > pj
	vector<int> fwd(n);
	for(int i=0;i<n;i++){
		for(int j=i+2;j<n;j++){
			if(p[i]>p[j])fwd[i]++;
		}
	}
	// rev[i][j]: number of k where i <= k < j where pk > pj
	// rev[i][j] = rev[i + 1][j] + (pi > pj)?
	vector<vector<int>> rev(n,vector<int>(n));
	for(int j=0;j<n;j++){
		for(int i=j-1;i>=0;i--){
			rev[i][j]=rev[i+1][j]+(p[i]>p[j]);
		}
	}
	int ans=0;
	for(int a=0;a<n;a++){
		int cur=0;
		for(int c=a+1;c<n;c++){
			cur-=rev[a+1][c];
			if(rev[a+1][c]&&p[c-1]>p[c])cur++;
			if(p[a]<p[c]){
				ans+=cur;
			}
			cur+=fwd[c];
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;cin>>t;
	while(t--)solve();
}