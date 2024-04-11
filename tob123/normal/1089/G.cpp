#include <bits/stdc++.h>
using namespace std;
const int n = 7;
bool u[n];
int T, K;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int t = 0; t < T; ++t){
		cin >> K;
		int pw = 0;
		for(int i = 0; i < 7; ++i){
			cin >> u[i];
			pw += u[i];
		}
		int m = 1e9;
		int sw = K/pw - 2;
		//cout << "sw: " << sw << endl;
		int lft = K - sw*pw;
		for(int s = 0; s < 7; ++s){
			int pre = 0;
			for(int i = s; i < 7; ++i)
				pre += u[i];
			int i = 0;
			while(pre < lft){
				pre += u[i % 7];
				i++;
			}
			m = min(m, 7-s + i + 7*sw);
		}
		cout << m << "\n";
	}
	return 0;
}