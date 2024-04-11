#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
string S;

int main(){
	cin >> T;
	while(T--){
		cin >> S;
		int res = 0;
		int cnt0 = 0;
		for(int i=0; i<sz(S); i++){
			if(S[i] == '0')
				cnt0++;
			else{
				ll val = 0;
				for(int j=i; j<min(sz(S), i+20); j++){
					cnt0++;
					val *= 2;
					if(S[j] == '1'){
						val++;
					}
					if(val <= cnt0)
						res++;
				}
				cnt0 = 0;
			}
		}
		cout << res << endl;
	}

  return 0;
}