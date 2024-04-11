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
int l[1000009],r[1000009];
string s[1000009];
struct UF {
		vi e;
			UF(int n) : e(n, -1) {}
				bool same_set(int a, int b) { return find(a) == find(b); }
					int size(int x) { return -e[find(x)]; }
						int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
							int join(int a, int b) {
								if(a==-1) return b;
								if(b==-1) return a;
										a = find(a), b = find(b);
												if (a == b) return a;
														if (e[a] > e[b]) swap(a, b);
																e[a] += e[b]; e[b] = a;
								return a;										
							}
};
UF dsu(1000009);
int join(int x,int y){
	return dsu.join(x,y);
}
void dfs(int u,int& cr,int& x,int& y){
	if(s[u]=="IN"){
		cr = l[u];
		if(l[u]==1) x = r[u],y=-1;
		else y=r[u],x=-1;
		return;
	}
	if(s[u]=="NOT"){
		l[u]--;
		dfs(l[u],cr,x,y);
		cr = !cr;
		swap(x,y);
		return;
	}
	int cr1,cr2,x1,x2,y1,y2;
	l[u]--;r[u]--;
	dfs(l[u],cr1,x1,y1);
	dfs(r[u],cr2,x2,y2);
	if(s[u] == "OR" ){
		cr = cr1|cr2;
		if(cr1==1&&cr2==0){
			x = x1,y = join(x2,y2);
			y = join(y,y1);
		}
		else if(cr1==0&&cr2==1){
			x = x2,y = join(x1,y1);
			y = join(y,y2);
		}
		else if(cr1==0&&cr2==0){
			x = join(x1,x2);y=join(y1,y2);
		}
		else if(cr1==1&&cr2==1){
			x = -1,y = join(join(x1,x2),join(y1,y2));
		}
		return;	
	}
	if(s[u] == "XOR" ){
		cr = cr1^cr2;
		if(cr1==1&&cr2==0){
			y = join(x2,y1);
			x = join(x1,y2);
		}
		else if(cr1==0&&cr2==1){
			y = join(x1,y2);
			x = join(x2,y1);
		}
		else if(cr1==0&&cr2==0){
			y = join(y1,y2);
			x = join(x1,x2);
		}
		else if(cr1==1&&cr2==1){
			y = join(x1,x2);
			x = join(y1,y2);
		}
		return;	
	}
	if(s[u] == "AND" ){
		cr = cr1&cr2;
		if(cr1==1&&cr2==0){
			y = y2;
			x = join(x1,join(x2,y1));
		}
		else if(cr1==0&&cr2==1){
			y = y1;
			x = join(x1,join(x2,y2));
		}
		else if(cr1==0&&cr2==0){
			x = join(join(x1,x2),join(y1,y2));
			y = -1;
		}
		else if(cr1==1&&cr2==1){
			y = join(y1,y2);
			x = join(x1,x2);
		}
		return;	
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int x= 0;
	rep(i,n){
		cin>>s[i]>>l[i];
		if(s[i]!="IN"&&s[i]!="NOT") cin>>r[i];
		if(s[i]=="IN") r[i] = x,x++;
	}
	int cr,xx,y;
	dfs(0,cr,xx,y);
	rep(i,x){
		if(xx!=-1&&dsu.same_set(xx,i)) cout<<0;
		else cout<<1;
	}
	return 0;
}