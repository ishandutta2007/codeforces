#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int MAX = N * 32;

int ch[MAX][2] , sz , n , m , x , y , A[N] , B[N] , rt , S[MAX];

void add(int x) {
	int now = rt;
	for(int i = 30;i >= 0;-- i) {
		++ S[now];
		int it = !!(x & (1 << i));
		if(!ch[now][it])ch[now][it] = ++ sz;
		now = ch[now][it];
	}
	++ S[now];
}

int query(int x) {
	int now = rt , res = 0;
	for(int i = 30;i >= 0;-- i) {
		-- S[now];
		int it = !!(x & (1 << i));
		if(!ch[now][it] || !S[ch[now][it]]) {
			now = ch[now][!it]; res |= (1 << i);
		}
		else now = ch[now][it];
	}
	-- S[now];
	return res;
}

main(void) {
	scanf("%d" , &n); rt = ++ sz;
	for(int i = 1;i <= n;++ i) scanf("%d" , &A[i]);
	for(int i = 1;i <= n;++ i) scanf("%d" , &B[i]) , add(B[i]);
	for(int i = 1;i <= n;++ i) printf("%d " , query(A[i]));
}