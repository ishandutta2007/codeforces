#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if((i+j)%2){
				cout << 'W';
			}
			else{
				cout << 'B';
			}
		}
		cout << "\n";
	}

  return 0;
}