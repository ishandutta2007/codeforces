#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll N, D, E;

int main(){
	cin >> N >> D >> E;
	ll best = N;
	for(int i=0; i<min(N+1, 1000000ll); i++){
		best = min(best, i%D + (N-i)%(E*5));
	}
	cout << best << endl;

  return 0;
}