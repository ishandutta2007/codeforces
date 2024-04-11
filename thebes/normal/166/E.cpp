#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int N, i, mat[4][4], a[4][4], b[4][4], j;
vector<int> bit;

void mul(int x){
	memset(b, 0, sizeof(b));
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(x) b[i][k]=(1LL*mat[i][j]*a[j][k]+b[i][k])%mod;
				else b[i][k]=(1LL*mat[i][j]*mat[j][k]+b[i][k])%mod;
			}
		}
	}
}

void cpy(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			mat[i][j]=b[i][j];
	}
}

int main(){
	scanf("%d",&N);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i==j) mat[i][j]=1;
			else a[i][j]=1;
		}
	}
	while(N) bit.insert(bit.begin(),N&1),N/=2;
	for(auto v : bit){
		mul(0); cpy();
		if(v) mul(1),cpy();
	}
	printf("%d\n",mat[0][0]);
	return 0;
}