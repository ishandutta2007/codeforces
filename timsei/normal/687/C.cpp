#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

bitset <N> B[N][N] , ans;

int n , c[N] , x , y , k;


int main(void) {
    scanf("%d%d" ,&n , &k);
    B[0][0][0] = 1;
    for(int i = 1;i <= n;++ i) {
	scanf("%d" , &c[i]);
	for(int j = 0;j <= k - c[i];++ j){
	    B[i][j + c[i]] |= B[i - 1][j] << c[i];
	    B[i][j + c[i]] |= B[i - 1][j];
	}
	for(int j = 0;j <= k;++ j) B[i][j] |= B[i - 1][j];
    }
    int that = 0;
    for(int i = 0;i <= k;++ i) if(B[n][k][i]) ++ that;
    cout << that << endl;
    for(int i = 0;i <= k;++ i) if(B[n][k][i]) cout << i << " ";
    puts("");
}