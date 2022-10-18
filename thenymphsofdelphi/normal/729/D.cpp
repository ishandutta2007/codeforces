#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back

signed main(){
	int n, a, b, k, cnt = 0, zcnt = 0, rem = 0;
	vector <int> shot, block;
	string s;
	cin >> n >> a >> b >> k >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			zcnt++;
		}
		else{
			if (zcnt > 0){
				block.pb(zcnt);
			}
			zcnt = 0;
		}
	}
	if (zcnt > 0){
		block.pb(zcnt);
	}
	for (int i = 0; i < block.size(); i++){
		rem += block[i] / b;
	}
	zcnt = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			zcnt++;
			if (zcnt == b){
				shot.pb(i);
				rem--;
				zcnt = 0;
			}
			if (rem < a){
				break;
			}
		}
		else{
			zcnt = 0;
		}
	}
	cout << shot.size() << endl;
	for (int i = 0; i < shot.size(); i++){
		cout << shot[i] + 1 << " ";
	}
}