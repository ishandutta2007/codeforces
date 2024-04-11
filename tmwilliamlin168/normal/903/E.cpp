#include <bits/stdc++.h>
using namespace std;

#define dump(...) do{print_vars(cout<<"# "<<#__VA_ARGS__<<'=',__VA_ARGS__);cout<<endl;}while(0)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vd=vector<double>;
using vvd=vector<vd>;
using vs=vector<string>;

template<typename T,typename U>bool chmin(T& a,const U& b){return a>b?(a=b,1):0;}
template<typename T,typename U>bool chmax(T& a,const U& b){return a<b?(a=b,1):0;}

void print_vars(ostream&){}
template<typename Car,typename... Cdr>
void print_vars(ostream& os,const Car& car,const Cdr&... cdr){
	print_vars(os<<car<<(sizeof...(cdr)?",":""),cdr...);
}

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<int I,typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<int I,typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	os<<get<I>(t)<<(sizeof...(Cdr)?",":"");
	print_tuple<I+1,Cdr...>(os,t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<0,Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

string solve_naive(vs ss)
{
	int k=ss.size(),n=ss[0].size();

	rep(i,k){
		string s=ss[0]; sort(all(s));
		string t=ss[i]; sort(all(t));
		if(s!=t)
			return "-1";
	}

	string s=ss[0]; sort(all(s));
	do{
		bool possible=true;
		rep(i,k){
			bool ok=false;
			rep(l,n) repi(r,l+1,n){
				swap(s[l],s[r]);
				ok|=s==ss[i];
				swap(s[l],s[r]);
			}
			if(!ok){
				possible=false;
				break;
			}
		}
		if(possible)
			return s;
	}while(next_permutation(all(s)));
	return "-1";
}

string solve(vs ss)
{
	int k=ss.size(),n=ss[0].size();

	rep(i,k){
		string s=ss[0]; sort(all(s));
		string t=ss[i]; sort(all(t));
		if(s!=t)
			return "-1";
	}

	bool dup=false;
	rep(i,n) repi(j,i+1,n) dup|=ss[0][i]==ss[0][j];

	vi cs(k);
	rep(i,k) rep(j,n) cs[i]+=ss[0][j]!=ss[i][j];

	string s=ss[0];
	rep(l,n) repi(r,l+1,n){
		bool ok=true;
		rep(i,k){
			int d1=(s[l]!=ss[i][l])+(s[r]!=ss[i][r]);
			swap(s[l],s[r]);
			int d2=(s[l]!=ss[i][l])+(s[r]!=ss[i][r]);
			int c=cs[i]+d2-d1;
			if(c>2){
				ok=false;
			}
			else if(c==2){
			}
			else if(c==0){
				if(!dup)
					ok=false;
			}
			swap(s[l],s[r]);
		}
		if(ok){
			swap(s[l],s[r]);
			return s;
		}
	}
	return "-1";
}

int main()
{
	#ifndef _GLIBCXX_DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr char endl='\n';
	#endif

	for(int k,n;cin>>k>>n&&k|n;){
		vs ss(k);
		rep(i,k) cin>>ss[i];
		//dump(solve_naive(ss));
		//dump(solve(ss));
		cout<<solve(ss)<<endl;
	}
}