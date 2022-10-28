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
bool p[1000009];
int mx[1000009];
void sieve(){
	repA(i,2,1000000){
		if(!p[i]){
			mx[i] = i;
			for(int j = 2*i; j<=1000000 ; j+=i) p[j] = true,mx[j] = max(mx[j],i);
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int x;cin>>x;sieve();
	int ans = x;
	int px = mx[x];
	repA(i,x-mx[x]+1,x){
		if(p[i]){
			ans = min(ans,i-mx[i]+1);
		}
	}
	cout<<ans;
	return 0;
}