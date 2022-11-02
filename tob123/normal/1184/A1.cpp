#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 5e5 + 5;

ll R;

int main(){
	cin >> R;
	for(ll x = 1; x*x < 1e13; ++x){
		ll z = R - x*x - x - 1;
		if(z % (2*x) == 0 && z > 0){
			cout << x << " " << z / (2*x) << endl;
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}