#include <bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;
typedef long long ll;

int N, K;

int A[n];
vector<int> J[n];

int main(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	for(int i=0; i<N; i++){
		int t;
		cin >> t;
		J[A[i]].push_back(t);
	}
	int cntE = 0;
	vector<int> res;
	for(int i=1; i<=K; i++){
		if(J[i].size() == 0)
			cntE++;
		else if(J[i].size() > 1){
			sort(J[i].begin(), J[i].end());
			for(int j=0; j<J[i].size()-1; j++){
				res.push_back(J[i][j]);
			}
		}
	}
	sort(res.begin(), res.end());
	ll sum = 0;
	for(int i=0; i<cntE; i++){
		sum += res[i];
	}
	cout << sum << endl;
	
	return 0;
}