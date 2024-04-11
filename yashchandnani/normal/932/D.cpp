#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int w[400009],p[400009],pt[400009][20];
ll ans[400009][20];
ll inf = 100000000000000000;
void add(int v,int r){
	while(r!=-1&&w[r]<w[v]){
		r=p[r];
	}
	p[v]=r;
	pt[v][0]=r;
	if(r!=-1) ans[v][0]=w[r];
	else ans[v][0] = inf;
	repA(i,1,19){
		if(pt[v][i-1]!=-1) pt[v][i] = pt[pt[v][i-1]][i-1];
		else pt[v][i] =-1;
		if(pt[v][i] == -1) ans[v][i] =inf;
		else ans[v][i] = ans[v][i-1]+ans[pt[v][i-1]][i-1];
	}
}
int query(int v,ll x,int mx){
	ll anss =0;
	repD(i,19,0){
		if(ans[v][i]<=x){
			 anss+=(1<<i);
			 x-=ans[v][i];
			 v=pt[v][i];
		}
	}
	return anss;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int q;ll last=0;cin>>q;
	int cnt = 1;
	w[1]=0;
	add(1,-1);
	rep(i,q){
		int t;ll r,x;cin>>t>>r>>x;
		r=r^last;
		x=x^last;
		if(t==1){
			cnt++;
			w[cnt] = x;
			add(cnt,r);
		}
		else{
			if(x<w[r]) last=0;
			else {
				x-=w[r];
				last = 1+query(r,x,19);
			}
			cout<<last<<'\n';
		}
	}
	return 0;
}