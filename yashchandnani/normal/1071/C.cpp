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
int a[100009];
vector<pii> ans;
int al[100],ar[100],am[100];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	set<int> s1,s2;
	rep(i,n) {
		cin>>a[i];
	}
	int cnt = 0;
	rep(i,n){
		if(a[i]){
			repA(j,i+1,i+1000){
				if(2*j-i>=n) break;
				if(a[j]&&a[2*j-i]){
					a[i]=a[j]=a[2*j-i] = 0;
					ans.pb(mp(i,2*j-i));
					break;
				}
			}
		}
		if(a[i]){
			cnt++;
			if(i%2) s1.insert(i);
			else s2.insert(i);
		}
	}
	int dbg = sz(ans);
	int mx = n/3+12;
	while(sz(s1)>1||sz(s2)>1){
		if(sz(s1)>1){
			auto it = s1.begin();
			auto it2 = s1.end();it2--;
			ans.pb(mp(*it,*it2));
			int x = *it,y = *it2;
			int z = (x+y)/2;
			a[x] = a[y] = 0;
			s1.erase(x);
			s1.erase(y);
			if(a[(x+y)/2]) {
				a[z] = 0;
				if(z%2) s1.erase(z);
				else s2.erase(z);
			}	
			else {
				a[z] = 1;
				if(z%2) s1.insert(z);
				else s2.insert(z);
			}
		}
		else{
			auto it = s2.begin();
			auto it2 = s2.end();it2--;
			ans.pb(mp(*it,*it2));
			int x = *it,y = *it2;
			int z = (x+y)/2;
			a[x] = a[y] = 0;
			s2.erase(x);
			s2.erase(y);
			if(a[(x+y)/2]) {
				a[z] = 0;
				if(z%2) s1.erase(z);
				else s2.erase(z);
			}	
			else {
				a[z] = 1;
				if(z%2) s1.insert(z);
				else s2.insert(z);
			}
		}
	}
	if(sz(s1)&&sz(s2)){
		int a = *s1.begin();
		int b = *s2.begin();
		if((2*a+b)%3==0&&(2*b+a)%3==0){
			int x = (2*a+b)/3;
			int y = (2*b+a)/3;
			if(x>=0&&x<n&&y>=0&&y<n){
			ans.pb(mp(a,y));
			ans.pb(mp(x,b));
			s1.erase(a);
			s2.erase(b);
			}
		}
	}
	int cnta = -1;
	if(sz(s1)){
		int re = *s1.begin()+1;
		if(!((re>3&&re<=(n-3))||(re>6)||(re<=(n-6)))){
				puts("NO");return 0;
			}
			if(re>6){
				cnta++;
				al[cnta]=re-6;am[cnta]=re-3;ar[cnta]=re;
				cnta++;
				al[cnta]=re-6;am[cnta]=re-5;ar[cnta]=re-4;
				cnta++;
				al[cnta]=re-5;am[cnta]=re-4;ar[cnta]=re-3;
			}
			else{
				if(re<=(n-6)){
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+3;al[cnta]=re;
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+5;al[cnta]=re+4;
					cnta++;
					ar[cnta]=re+5;am[cnta]=re+4;al[cnta]=re+3;
				}
				else{
					cnta++;
					al[cnta]=re-3;am[cnta]=re;ar[cnta]=re+3;
					cnta++;
					al[cnta]=re-3;am[cnta]=re-1;ar[cnta]=re+1;
					cnta++;
					al[cnta]=re-1;am[cnta]=re+1;ar[cnta]=re+3;
				}
			}
	}
	if(sz(s2)){
		int re = *s2.begin()+1;
		if(!((re>3&&re<=(n-3))||(re>6)||(re<=(n-6)))){
				puts("NO");return 0;
			}
			if(re>6){
				cnta++;
				al[cnta]=re-6;am[cnta]=re-3;ar[cnta]=re;
				cnta++;
				al[cnta]=re-6;am[cnta]=re-5;ar[cnta]=re-4;
				cnta++;
				al[cnta]=re-5;am[cnta]=re-4;ar[cnta]=re-3;
			}
			else{
				if(re<=(n-6)){
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+3;al[cnta]=re;
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+5;al[cnta]=re+4;
					cnta++;
					ar[cnta]=re+5;am[cnta]=re+4;al[cnta]=re+3;
				}
				else{
					cnta++;
					al[cnta]=re-3;am[cnta]=re;ar[cnta]=re+3;
					cnta++;
					al[cnta]=re-3;am[cnta]=re-1;ar[cnta]=re+1;
					cnta++;
					al[cnta]=re-1;am[cnta]=re+1;ar[cnta]=re+3;
				}
			}
	}
	cnta++;
	{
		cout<<"YES\n";
		cout<<sz(ans)+cnta<<'\n';
		if(sz(ans)+cnta>mx) {
			cout<<sz(ans)<<' '<<cnta<<' '<<dbg<<endl;
			exit(0);
		}
		trav(i,ans) {
			if(i.fst>i.snd) swap(i.fst,i.snd);
			cout<<i.fst+1<<' '<<(i.fst+i.snd)/2+1<<' '<<i.snd+1<<'\n';
		}
		rep(i,cnta){
			cout<<al[i]<<' '<<am[i]<<' '<<ar[i]<<'\n';		
		}
	}
	return 0;
}