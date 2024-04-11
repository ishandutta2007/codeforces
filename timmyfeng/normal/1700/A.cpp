#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll t, n ,m;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;
  while(t--){
  	cin >> n >> m;
  	cout << m*(m-1+n*n+n)/2 << nl;
  }
}