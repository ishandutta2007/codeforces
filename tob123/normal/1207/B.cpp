#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 120;

int N, M;
string A[n], B[n];
vector<pair<int,int>> res;

int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		A[i].resize(M);
		for(int j=0; j<M; j++){
			cin >> A[i][j];
		}
	}
	for(int i=0; i<N; i++){
		B[i] = "";
		for(int j=0; j<M; j++){
			B[i] += '0';
		}
	}
	for(int i=0; i<N-1; i++){
		for(int j=0; j<M-1; j++){
			if(A[i][j] == '1' && A[i+1][j] == '1' && A[i][j+1] == '1' && A[i+1][j+1] == '1'){
				B[i][j] = '1';
				B[i+1][j] = '1';
				B[i][j+1] = '1';
				B[i+1][j+1] = '1';
				res.push_back(make_pair(i+1, j+1));
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(A[i][j] != B[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << sz(res) << endl;
	for(auto p : res){
		cout << p.first << " " << p.second << endl;
	}

  return 0;
}