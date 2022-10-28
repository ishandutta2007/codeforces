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
vector<pii> ans[16];
bool vis[201][201];
pii lst[5][16][201][201];
void pre(){
	ans[0].pb(mp(0,0));
	vector<pii> p,p2;
	rep(i,24) p.pb(mp(25,i));
	rep(i,24) p.pb(mp(i,25));
	repA(i,26,200) p.pb(mp(i,i-2)),p.pb(mp(i-2,i));
	rep(i,14) p2.pb(mp(15,i)),p2.pb(mp(i,15));
	repA(i,16,200) p2.pb(mp(i,i-2)),p2.pb(mp(i-2,i));
	rep(ii,4){
		vector<pii> ns[16];
		rep(jj,15){
			int xx = jj/4,yy=jj%4;
			if(xx==3||yy==3) {
				trav(k,ans[jj]) ns[jj].pb(k);
				continue;
			}
			trav(i,p){
				trav(j,ans[jj]){
					if(i.fst+j.fst>200||i.snd+j.snd>200) continue;
					if(i.fst>i.snd){
						lst[ii][(xx+1)*4+yy][(j.fst+i.fst)][(j.snd+i.snd)] = i;
						ns[(xx+1)*4+yy].pb(mp(j.fst+i.fst,j.snd+i.snd));
					}
					else {
						lst[ii][(xx)*4+yy+1][(j.fst+i.fst)][(j.snd+i.snd)] = i;
						ns[xx*4+(yy+1)].pb(mp(j.fst+i.fst,j.snd+i.snd));
					}
				}
			}
		}
		ll tl = 0;
		rep(i,16){
			ans[i].clear();
			fill(vis);
			trav(k,ns[i]) if(!vis[k.fst][k.snd]) vis[k.fst][k.snd] = 1,ans[i].pb(k);
		}
	}
	rep(ii,1){
		vector<pii> ns[16];
		rep(jj,15){
			int xx = jj/4,yy=jj%4;
			if(xx==3||yy==3) {
				trav(k,ans[jj]) ns[jj].pb(k);
				continue;
			}
			trav(i,p2){
				trav(j,ans[jj]){
					if(i.fst+j.fst>200||i.snd+j.snd>200) continue;
					if(i.fst>i.snd){
						lst[4][(xx+1)*4+yy][(j.fst+i.fst)][(j.snd+i.snd)] = i;
						ns[(xx+1)*4+yy].pb(mp(j.fst+i.fst,j.snd+i.snd));
					}
					else {
						lst[4][(xx)*4+yy+1][(j.fst+i.fst)][(j.snd+i.snd)] = i;
						ns[xx*4+(yy+1)].pb(mp(j.fst+i.fst,j.snd+i.snd));
					}
				}
			}
		}
		rep(i,16){
			ans[i].clear();
			fill(vis);
			trav(k,ns[i]) if(!vis[k.fst][k.snd]) vis[k.fst][k.snd] = 1,ans[i].pb(k);
			sort(all(ans[i]));
		}
	}


}

void solve(){

	int a,b;cin>>a>>b;
	int ns = -1,mxix=-1;
	rep(i,16){
		int xx = i/4,yy=i%4;
		auto it = lower_bound(all(ans[i]),mp(a,b));
		if(it!=ans[i].end()&&(*it)== mp(a,b)){
			if(ns<xx) ns=xx,mxix=i;
		}
	}
	if(mxix==-1) cout<<"Impossible\n";
	else{
		int xx = mxix/4,yy=mxix%4;
		cout<<xx<<":"<<yy<<'\n';
		vector<pii> az;
		int cnt = 4;
		while(a||b){
			if(lst[cnt][mxix][a][b]!=mp(0,0)) az.pb(lst[cnt][mxix][a][b]);
			if(lst[cnt][mxix][a][b].fst>lst[cnt][mxix][a][b].snd) xx--;
			else if(lst[cnt][mxix][a][b]!=mp(0,0)) yy--;
			pii z = lst[cnt][mxix][a][b];
			cnt--;
			a-=z.fst;
			b-=z.snd;
			mxix = xx*4+yy;
		}
		while(sz(az)){
			cout<<az.back().fst<<":"<<az.back().snd<<' ';
			az.pop_back();
		}
		cout<<'\n';
	}
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	
	
	
	return 0;
}