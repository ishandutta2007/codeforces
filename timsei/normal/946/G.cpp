%:pragma GCC optimize(2)
%:pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5;

int A[N] , n , m , x , y , id[N] , tot , S[N] , L[N];

map <int , int> Map;
unordered_map <int , int> C;
map <int , int> ::iterator it;

#define lowbit(x) (x & (-x))

void add(int x , int v) {
	for(register int i = x;i < N;i += lowbit(i)) S[i] = max(S[i] , v);
}

int sum(int x) {
	int res = 0;
	for(register int i = x;i;i -= lowbit(i)) res = max(res , S[i]);
	return res;
}

main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) scanf("%d" ,&A[i]) , ++ Map[A[i]] , ++ Map[A[i] - i] , ++ Map[A[i] - i + 1];
	++ Map[-1e9]; A[0] = -1e9;
	for(it = Map.begin();it != Map.end(); ++ it) {
		id[++ tot] = it -> first; C[it -> first] = tot;
	}
	for(register int i = 1;i <= n;++ i) {
		int now = C[A[i] - i];
		L[i] = sum(now) + 1;
		add(now , L[i]);
	}
	memset(S , 0 , sizeof(S));
	int ans = 0;
	for(register int i = n;i >= 1;-- i) {
		int now = C[A[i] - i + 1];
		now = tot - now + 1;
		ans = max(ans , L[i - 1] + sum((tot - C[A[i - 1] - i + 1] + 1)));
		add(now , sum(now) + 1);
	}
	cout << n - 1 - ans << endl;
}