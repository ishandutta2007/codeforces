#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 205;
int S[N][N], C[N][N], pc[N][N], D[N][N], W[N][N], P[N];

void rek(int i, int j){
	if(i >= j)return;
	int k = W[i][j];
	if(k-1 >= i){
		int a = W[i][k-1];
		P[a] = k;
		rek(i,k-1);
	}
	if(k + 1 <= j){
		int b = W[k+1][j];
		P[b] = k;
		rek(k+1, j);
	}
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
	{
		S[i][j] = C[i][j] = pc[i][j] = D[i][j] =  0;
		P[i] = -1;
		W[i][i] = i;
	}


	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
	{
		cin >> C[i][j];
	}
	
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
	{
		pc[i][j+1] = C[i][j] + pc[i][j];
	}
	
	for(int i = 0; i < n; ++i)
	for(int j = i; j < n; ++j)
	{
		for(int k = 0; k < n; ++k){
			if(k < i || k > j){
				S[i][j] += (pc[k][j+1] - pc[k][i]);
			}
		}
	}
	
	for(int L = 0; L < n; ++L)
	for(int st = 0; st+L < n; ++st)
	{
		int i = st;
		int j = st+L;
		if(i != j){
			D[i][j] = 1e18;
			int t = i;
			for(int k = i; k <= j; ++k){
				if(k == i){
					W[i][j] = i;
					t = S[i+1][j] + D[i+1][j];
				}
				else if(k == j){
					t = (S[i][j-1] + D[i][j-1]);
				}
				else {
					t = (D[i][j], S[i][k-1] + D[i][k-1]   +  S[k+1][j] + D[k+1][j] );
				}
				if(D[i][j] > t){
					W[i][j] = k;
					D[i][j] = t;
				}
			}
		}
		else D[i][j] = 0;
	}

	rek(0, n-1);
	for(int i = 0; i < n; ++i){
		cout << P[i] + 1 << ' ';
	}
	cout << '\n';
}