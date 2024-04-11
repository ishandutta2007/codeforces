#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

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
bool p[1200009];
int ans2[1200009];
void sieve(){
	ans2[1]=0;
	repA(i,2,1200000){
		ans2[i] = ans2[i-1];
		if(!p[i]){
			ans2[i]++;
			for(int j =i;j<=1200000;j+=i){
				p[j] =true;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int ans[1200009]={0};
	repA(i,1,1200000){
			 vi v;
			 int j =i;
			 while(i){
			 v.pb(i%10);i/=10;
			}
			 i = j;
		 bool f  = false;
		 rep(i,sz(v)/2){
			 if(v[i]!=v[sz(v)-1-i]) f= true;
		 }
		if(!f) ans[i]++;
		ans[i]+=ans[i-1];
	}
	sieve();
	int p,q;cin>>p>>q;
	int fns =0;
	repA(i,1,1200000){
		if(p*ans[i]>=q*ans2[i]) fns =i;
	}
	cout<<fns;
	return 0;
}