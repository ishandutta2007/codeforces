#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e2 + 10;

int n, m;
long long a[MAXN];
bool dp[MAXN][MAXN];
vector<pair<int,long long>> h;
bool used[MAXN];


void init() {
	for (pair<int,long long> r : h) {
		ll curHP = r.second;
		dp[r.first][r.first] = true;
		for(int i=r.first+1; i<n; i++){
			curHP += a[i];
			dp[r.first][i] = dp[r.first][i-1] && curHP >= 0;	
		}
		curHP = r.second;
		for(int i=r.first-1; i>=0; i--){
			curHP += a[i];
			dp[r.first][i] = dp[r.first][i+1] && curHP >= 0;	
		}
	}
}

void printDP(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int si, hi;
		cin >> si >> hi;
		si--;
		h.push_back(make_pair(si, hi));
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//sort(h.begin(), h.end());
	init();
	//printDP();
	for(int curF=0; curF<n; curF++){
		int lP=curF, rP=curF;
		for(int i=0; i<m; i++){
			used[i] = false;
		}
		vector<int> R;
		for(int j=0; j<m; j++){
			for(int i=0; i<m; i++){
				if(used[i])
					continue;
				int f = h[i].first;
				if(f <= lP){
					if(dp[f][lP]){
						if(lP == rP)
							rP++;
						lP = f-1;	
						R.push_back(i+1);
						used[i] = true;
						break;
					}
				}
				else if(f >= rP){
					if(dp[f][rP]){
						rP = f+1;
						used[i] = true;
						R.push_back(i+1);
						break;
					}
				}
				else{
					R.push_back(i+1);
					used[i] = true;
					break;
				}
			}
		}
		if(R.size() == m){
			cout << curF+1 << endl;
			for(auto x : R)
				cout << x << " ";
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;


	return 0;
}