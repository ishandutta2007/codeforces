#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M;
vector<string> S;
vector<vector<char>> B;
vector<vector<char>> B2;

int main(){
	cin >> N >> M;
	S.resize(N);
	B.resize(N+2);
	B2.resize(N+2);
	for(int i=0; i<N; i++){
		cin >> S[i];
		B[i] = vector<char>(M+2, 0);
		B2[i] = vector<char>(M+2, 0);
	}
	B[N] = vector<char>(M+2, 0);
	B[N+1] = vector<char>(M+2, 0);
	B2[N] = vector<char>(M+2, 0);
	B2[N+1] = vector<char>(M+2, 0);
	B[1][1] = 1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(S[i-1][j-1] == '.' && (B[i-1][j]>0 || B[i][j-1]>0)){
				B[i][j] = 1;
			}
		}
	}
	B2[N][M] = 1;
	for(int i=N; i>=1; i--){
		for(int j=M; j>=1; j--){
			if(S[i-1][j-1] == '.' && (B2[i+1][j]>0 || B2[i][j+1]>0)){
				B2[i][j] = 1;
			}
			else{
				B[i][j] = 0;
			}
		}
	}
	int bst = 100;
	for(int i=1; i<N+M-2; i++){
		int cnt = 0;
		for(int j=max(0, i-M+1); j<=min(N-1, i); j++){
			cnt += B[j+1][i-j+1];
		}
		bst = min(bst, cnt);
	}
	cout << bst << endl;


  return 0;
}