#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int d1[N][N][2] , d2[N][N][2] , n , m , x , y , a[N];

struct NODE {
	int zero , one;
}A , B , C;

NODE operator + (NODE xxx , NODE yyy) {
	NODE ret;
	ret.zero = xxx.zero + yyy.zero;
	ret.one = xxx.one + yyy.one;
	ret.one = max(ret.one , ret.zero);
	return ret;
}

main(void) {
	for(int i = scanf("%d" , &n);i <= n;++ i) scanf("%d" , &a[i]) , -- a[i];
	for(int i = 1;i <= n;++ i) {
		d1[i][i][a[i]] = 1;
		d1[i][i][1] = max(d1[i][i][1] , d1[i][i][0]);
		for(int j = i + 1;j <= n;++ j) {
			if(a[j]) {
				d1[i][j][1] = d1[i][j - 1][1] + 1;
				d1[i][j][0] = d1[i][j - 1][0];
			}
			else {
				d1[i][j][0] = d1[i][j - 1][0] + 1;
				d1[i][j][1] = max(d1[i][j - 1][1] , d1[i][j][0]);
			}
		}
		d2[i][i][a[i]] = 1;
		d2[i][i][1] = max(d2[i][i][1] , d2[i][i][0]);
		for(int j = i - 1;j >= 1;-- j) {
			if(a[j]) {
				d2[i][j][1] = d2[i][j + 1][1] + 1;
				d2[i][j][0] = d2[i][j + 1][0];
			}
			else {
				d2[i][j][0] = d2[i][j + 1][0] + 1;
				d2[i][j][1] = max(d2[i][j + 1][1] , d2[i][j][0]);
			}
		}
	}
	int ans = 0;
	for(int l = 1;l <= n;++ l) {
		for(int r = l;r <= n;++ r) {
			ans = max(ans , ((NODE){d1[1][l - 1][0] , d1[1][l - 1][1]} + (NODE){d2[l][r][0] , d2[l][r][1]} + (NODE){
			d1[r + 1][n][0] , d1[r + 1][n][1]}).one);
		}
	}
	cout << ans << endl;
}