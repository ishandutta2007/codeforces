#include <bits/stdc++.h>
using namespace std;
int n = 1e5;
const int sN = 2e6;
vector<int> P;
bool dp[sN];
pair<int, int> BT[sN];
int N;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	int Z = N;
	while(Z != 1){
		for(int i = 2; i*i <= Z; ++i){
			if(Z % i == 0){
				if(P.size() == 0 || P[P.size()-1] != i)
					P.push_back(i);
				Z /= i;
				goto A;
			}
		}
		if(P.size() == 0 || P[P.size()-1] != Z)
			P.push_back(Z);
		break;
		A:;
	}
	/*for(auto p: P)
		cout << p << " ";
	cout << endl;
*/
	if(P.size() >= 3){
		int sP = P[0];
		if(sP > 100){
			n = 1e6;
		}
		dp[0] = true;
		for(int i = 0; i < n; ++i){
			if(dp[i]){
				for(int p: P){
					if(i+p <=n){
						dp[i+p] = true;
						BT[i+p] = {p, i};
					}
				}
			}
		}
		vector<pair<int,int>> res;
		int lastI;
		if(N-1 >= n){
			lastI = -1;
			for(int i = n-sP; i < n; ++i){
				if(!dp[i]){
					cout << "NO\n";
					return 0;
				}
				if((N-1-i)% sP == 0)
					lastI = i;
			}
		
			int c = (N-1-lastI)/sP;
			res.push_back({c, N/sP});
		}else{
			if(!dp[N-1]){
				cout << "NO\n";
				return 0;
			}
			lastI = N-1;
		}

		while(lastI != 0){
			int nextI, p;
			tie(p, nextI) = BT[lastI];
			res.push_back({1, N/p});
			lastI = nextI;
		}
		cout << "YES\n" << res.size() << endl;
		for(auto pr : res){
			cout << pr.first << " " << pr.second << "\n";
		}
		return 0;
	}else if (P.size() <= 1){
		cout << "NO\n";
				return 0;
	}else{
		for(int i = 0; i < P[0]; ++i){
			if((N-1 - (i*P[1])) % P[0] == 0){
				cout << "YES\n";
				if(i == 0){
					int c = (N-1)/P[0];
					cout << 1 << "\n" << c << (N/P[0]) << endl;
				}else{
					int c = (N-1- (i*P[1]))/P[0];
					cout << 2 << "\n" << i << " " << (N/P[1]) << "\n" << c << " " << (N/P[0]) << endl;
				}
				return 0;
			}
		}
		cout << "NO\n";
				return 0;
	}
}