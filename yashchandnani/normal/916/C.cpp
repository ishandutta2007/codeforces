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
vi primes;
bool p[2000000];
void sieve(){
	repA(i,2,1500000){
		if(!p[i]) primes.pb(i);
		for(int j = i;j<=1500000;j+=i) p[j] = true;
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	sieve();
	int n,m;cin>>n>>m;
	m-=n-1;
	cout<<primes[n-1]<<' '<<primes[n-1]<<'\n';
	primes[0] = 0;
	repA(i,1,n-1){
		cout<<i<<' '<<i+1<<' '<<primes[i]-primes[i-1]<<'\n';
		rep(j,min(n-i-1,m)){
			cout<<i<<' '<<i+2+j<<' '<<1000000000<<'\n';
		}
		m-=min(m,n-i-1);
	}
	return 0;
}