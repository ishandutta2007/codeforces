#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int T;
	cin >> T;
	while(T--){
		ll s, i, e;
		cin >> s >> i >> e;
		if(s <= i){
			e -= i-s+1;
			s = i+1;
		}
		if(e < 0){
			cout << 0 << "\n";
		}
		else{
			//cout << ". " << (e-(s-i)+2) << "\n";
			//cout << ". " << ((e-(s-i)+2)/2) << "\n";
			if(s-i > e)
				cout << e+1 << "\n";
			else
				cout << e+1-((e-(s-i)+2)/2) << "\n";
		}
	}

  return 0;
}