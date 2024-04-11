#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll Q, C, M, X;

int main(){
	cin >> Q;
	while(Q--){
		cin >> C >> M >> X;
		ll res = min((C+M+X)/3, min(C, M));
		cout << res << "\n";
	}

  return 0;
}