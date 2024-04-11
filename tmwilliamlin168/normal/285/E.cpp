#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll M=1e9+7;
const int mxN=1000;

ll F[mxN+1][mxN+1][5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	F[1][0][4]=1;
	for(int i=2; i<=n; ++i) {
		for(int j=0; j<=min(i, n); ++j) {
			//A[i-1]!=i, A[i]!=i-1
			F[i][j][0]=((i-3-j)*F[i-1][j][0]+(i-2-j)*(F[i-1][j][1]+F[i-1][j][2]+F[i-1][j][4])+(i-1-j)*F[i-1][j][3])%M;
			if(j+1<=i-1)
				F[i][j][0]=(F[i][j][0]+(j+1)*(F[i-1][j+1][0]+F[i-1][j+1][4])+j*(F[i-1][j+1][1]+F[i-1][j+1][2])+(j-1)*F[i-1][j+1][3])%M;
			//A[i-1]!=i, A[i]=i-1
			F[i][j][1]=(F[i-1][j][2]+F[i-1][j][3])%M;
			if(j>=1)
				F[i][j][1]=(F[i][j][1]+F[i-1][j-1][0]+F[i-1][j-1][1])%M;
			//A[i-1]=i, A[i]!=i-1
			F[i][j][2]=(F[i-1][j][1]+F[i-1][j][3])%M;
			if(j>=1)
				F[i][j][2]=(F[i][j][2]+F[i-1][j-1][0]+F[i-1][j-1][2])%M;
			//A[i-1]=i, A[i]=i-1
			if(j>=2)
				F[i][j][3]=F[i-1][j-2][4];
			//A[i]=i
			F[i][j][4]=(F[i-1][j][0]+F[i-1][j][1]+F[i-1][j][2]+F[i-1][j][3]+F[i-1][j][4])%M;
		}
	}
	cout << (F[n][k][0]+F[n][k][1]+F[n][k][2]+F[n][k][3]+F[n][k][4])%M;
	//cout << endl << F[n][k][0] << " " << F[n][k][1] << " " << F[n][k][2] << " " << F[n][k][3] << " " << F[n][k][4] << endl;
}