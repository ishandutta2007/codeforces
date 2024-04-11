#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, B, P, F, H, C;

int main(){
	cin >> T;
	while(T--){
		cin >> B >> P >> F;
		cin >> H >> C;
		B /= 2;
		int best = 0;
		for(int i=0; i<=B; i++){
			best = max(best, min(i, P) * H + min(B-i, F) * C);
		}
		cout << best << endl;
	}

  return 0;
}