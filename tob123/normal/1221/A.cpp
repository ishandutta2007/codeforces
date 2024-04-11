#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int Q, N;

int main(){
	cin >> Q;
	while(Q--){
		cin >> N;
		ll sum = 0;
		ll x;
		for(int i=0; i<N; i++){
			cin >> x;
			if(x <= 2048)
				sum += x;
		}
		if(sum >= 2048){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}

  return 0;
}