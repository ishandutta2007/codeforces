#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int S1[N][3] , S2[N][3] , n , m , x , y , l , r , a , b , c , d , sA[N] , tA[N];

char s[N] , t[N];

string ans;

main(void) {
	scanf("%s" , s + 1);
	scanf("%s" , t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for(int i = 1;i <= n;++ i) {
		for(int j = 0;j < 3;++ j) S1[i][j] = S1[i - 1][j];
		++ S1[i][s[i] - 'A'];
		if(s[i] == 'A') sA[i] = sA[i - 1] + 1;
	}
	for(int i = 1;i <= m;++ i) {
		for(int j = 0;j < 3;++ j) S2[i][j] = S2[i - 1][j];
		++ S2[i][t[i] - 'A'];
		if(t[i] == 'A') tA[i] = tA[i - 1] + 1;
	}
	int qqq;
	for(scanf("%d" , &qqq);qqq --;) {
		scanf("%d%d%d%d" , &a , &b , &c , &d);
		int A[3] , B[3];
		for(int i = 0;i < 3;++ i) {
			A[i] = S1[b][i] - S1[a - 1][i];
			B[i] = S2[d][i] - S2[c - 1][i];
		}
		bool flag = 0;
		int Aa = min(sA[b] , b - a + 1) , Ab = min(tA[d] , d - c + 1);
		if(Aa < Ab) {
			ans = ans + "0"; continue;
		}
		else {
			if(Aa != Ab) flag = 1;
			int now = (Aa - Ab) % 3;
			if(now != 0) ++ A[1] , ++ A[2];
		}
		
		A[0] -= Aa;
		if(A[0]) flag = 1;
		if((A[1] + A[2]) > (B[1] + B[2])) {
			ans = ans + "0"; continue;
		}
		if(((B[1] + B[2] - A[1] - A[2]) & 1) || ((!flag) && (!(A[1] + A[2])) && (B[1] + B[2] - A[1] - A[2]))) {
			ans = ans + "0"; continue;
		}
		ans = ans + "1";
	}
	cout << ans << endl;
}