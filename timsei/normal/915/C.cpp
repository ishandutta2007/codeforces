#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
#define int long long

int a , b , A[N]  , B[N] , na , nb , num[N];

bool vis[N];

int Min(void) {
	int ans = 0;
	for(int i = 0;i <= 9;++ i) {
		for(int j = 1;j <= num[i];++ j) ans = ans * 10 + i;
	}
	return ans;
}

int dfs(int pos , int limit) {
	if(!pos) return 0;
	if(!limit) {
		int ans = 0;
		for(int i = 9;i >= 0; -- i) {
			for(int j = 1;j <= num[i];++ j) {
				ans = ans * 10 + i;
			}
		}
		return ans;
	}
	else {
		int res = 0;
		for(int i = pos - 1;i >= 1;-- i) {
			res = res * 10 + B[i];
		}
		if(!num[B[pos]]) {
			int xxx = B[pos];
			while(!num[xxx]) -- xxx;
			-- num[xxx]; 
			int ans = xxx * pow(10 , pos - 1) + dfs(pos - 1 , 0);
			++ num[xxx];
			return ans;
		}
		else {
			-- num[B[pos]];
			int that = Min();
			//cerr << res << " "<< that << endl;
			if(that > res) {
				++ num[B[pos]];
				int xxx = B[pos];
				-- xxx; while(!num[xxx]) -- xxx;
				-- num[xxx];
				int ans = xxx * pow(10 , pos - 1) + dfs(pos - 1 , 0);
				++ num[xxx];
				return ans;
			} 
			else {
				int ans = B[pos] * pow(10 , pos - 1) + dfs(pos - 1 , 1);
				++ num[B[pos]];
				return ans;
			}
		}
	}
}

main(void) {
	cin >> a >> b;
	while(a) {
		A[++ na] = a % 10;
		a /= 10;
	}
	while(b) {
		B[++ nb] = b % 10;
		b /= 10;
	}
	sort(A + 1 , A + na + 1);
	for(int i = 1;i <= na;++ i) ++ num[A[i]];
	if(nb > na) {
		for(int i = na;i >= 1;-- i) cout << A[i];
		return 0;
	}
	cout << dfs(na , 1) << endl;
}