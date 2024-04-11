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
string s[3009],t[3009];
string ss,tt;
int l[3009],r[3009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>s[i];
	rep(i,n) cin>>t[i];
	rep(i,n){
		if(s[i]!=t[i]){
			rep(j,sz(s[i])){
				if(s[i][j]!=t[i][j]) {
					l[i] = j;
					break;
				}
			}
			repD(j,sz(s[i])-1,0){
				if(s[i][j]!=t[i][j]) {
					r[i] = j;
					break;
				}
			}
			if(ss==""){
				ss = s[i].substr(l[i],r[i]-l[i]+1);
				tt = t[i].substr(l[i],r[i]-l[i]+1);
			}
			else {
				if(ss!=s[i].substr(l[i],r[i]-l[i]+1) || tt != t[i].substr(l[i],r[i]-l[i]+1)){
					cout<<"NO";
					exit(0);
				}
			}
		}
		else l[i] = r[i] = -1;
	}
	while(1){
		char sx = '$',tx='$';
		bool fg = 0;
		rep(i,n){
			if(l[i]!=-1){
				if(l[i]==0) {
					fg = 1;
					break;
				}
				if(sx=='$'){
					sx = s[i][l[i]-1];
					tx = t[i][l[i]-1];
				}
				else{
					if(sx!=s[i][l[i]-1] || tx!= t[i][l[i]-1]) {
						fg = 1;
						break;
					}
				}
			}
		}
		if(fg) break;
		rep(i,n) if(l[i]!=-1) l[i]--;
		string tem2(1,tx);
		tt = tem2+tt;
		string tem(1,sx);
		ss = tem+ss;
	}
	while(1){
		char sx = '$',tx='$';
		bool fg = 0;
		rep(i,n){
			if(r[i]!=-1){
				if(r[i]==sz(s[i])-1) {
					fg = 1;
					break;
				}
				if(sx=='$'){
					sx = s[i][r[i]+1];
					tx = t[i][r[i]+1];
				}
				else{
					if(sx!=s[i][r[i]+1] || tx!= t[i][r[i]+1]) {
						fg = 1;
						break;
					}
				}
			}
		}
		if(fg) break;
		rep(i,n) if(r[i]!=-1) r[i]++;
		string tem2(1,tx);
		tt = tt+tem2;
		string tem(1,sx);
		ss = ss+tem;
	}
	rep(i,n){
		if(l[i]==-1&&s[i].find(ss)!=string::npos){
			cout<<"NO";
			exit(0);
		}
	}
	rep(i,n){
		if(l[i]!=-1&&r[i]>0&&(s[i].substr(0,r[i])).find(ss)!=string::npos){
			cout<<"NO";
			exit(0);
		}
	}
	cout<<"YES\n";
	cout<<ss<<'\n';
	cout<<tt<<'\n';
	return 0;
}