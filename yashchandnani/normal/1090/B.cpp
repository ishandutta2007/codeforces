#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
map<string,int> m;
int cnt;
string ans[100];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s;cin>>s;
	while(cin>>s){
		if(s=="\\begin{thebibliography}{99}") break;
		if(s.find('{')!=string::npos){
			size_t pos1 = s.find('{') ,pos2=s.find('}');
			string t = s.substr(pos1+1,pos2-pos1-1);
			m[t] = cnt;
			cnt++;
		}
	}
	getline(cin,s);
	bool fg = 0;
	int cnt2 = 0;
	while(getline(cin,s)){
			if(s=="\\end{thebibliography}") break;
			size_t pos1 = s.find('{') ,pos2=s.find('}');
			string t = s.substr(pos1+1,pos2-pos1-1);
			if(m[t]!=cnt2) fg=1;
			cnt2++;
			ans[m[t]] = s;
	}
	if(fg){
		cout<<"Incorrect\n";
		cout<<"\\begin{thebibliography}{99}\n";
		rep(i,cnt2) cout<<ans[i]<<'\n';
		cout<<"\\end{thebibliography}\n";
	}
	else cout<<"Correct";	
	return 0;
}