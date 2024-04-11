#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;

int main(){
	cin >> T;
	while(T--){
		ll n, x, d, h;
		cin >> n >> x;
		ll bestM = 0, bestD = 0;
		for(int i=0; i<n; i++){
			cin >> d >> h;
			bestD = max(bestD, d-h);
			bestM = max(bestM, d);
		}
		x -= bestM;
		if(x <= 0)
			cout << 1 << "\n";
		else{
			if(bestD == 0)
				cout << -1 << "\n";
			else{
				cout << 1+(x+bestD-1)/bestD << "\n";
			}
		}
	}

  return 0;
}