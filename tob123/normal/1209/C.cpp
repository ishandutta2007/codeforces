#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N;
string S;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		cin >> S;
		int ma = 0;
		int si = -1;
		for(int i=0; i<N; i++){
			int cur = S[i]-'0';
			if(cur < ma){
				si = i;
				break;
			}
			ma = max(ma, cur);
		}
		if(si == -1){
			for(int i=0; i<N; i++){
				cout << '1';
			}
			cout << "\n";
		}
		else{
			string res = "";
			char i1=S[si], i2=ma+'0';
			char i2m = '9'+1;
			for(int i=0; i<si; i++){
				if(S[i] <= S[si])
					res += '1';
				else{
					res += '2';
					i2m = min(i2m, S[i]);
				}
			}
			for(int i=si; i<N; i++){
				if(S[i] >= i2){
					i2 = S[i];
					res += '2';
					i2m = min(i2m, S[i]);
				}
				else if(S[i] >= i1){
					res += '1';
					i1 = S[i];
				}
				else{
					res = "-";
					break;
				}
			}
			if(i2m < i1)
				res = "-";
			cout << res << "\n";
		}
	}

  return 0;
}