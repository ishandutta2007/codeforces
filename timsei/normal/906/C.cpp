#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 23;

int dp[1 << N] , pre[1 << N] , n , m , x , y , way[N] , S[1 << N];

bool inq[1 << N];

#define F(i , n) for(int i = 0;i < n;++ i)

queue <int> q;

int main(void) {
	scanf("%d%d" , &n , &m);
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d" , &x , &y);
		-- x; -- y; way[x] |= (1 << y); way[y] |= (1 << x);
	}
	F(i , n) way[i] |= (1 << i);
	memset(dp , 63 , sizeof(dp));
	F(i , 1 << n) {
		int flag = 1;
		F(j , n) if(((1 << j) & i) && (way[j] & (i)) != i) flag = 0;
		if(flag) {
			q.push(i); dp[i] = 0; pre[i] = 0; S[i] = 0; inq[i] = 1;
		}
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		if(now == (1 << n) - 1) break;
		F(i , n) {
			if(now & (1 << i)) {
				int that = now | way[i];
				if(inq[that]) continue;
				inq[that] = 1; dp[that] = dp[now] + 1; pre[that] = now; S[that] = i + 1;
				q.push(that);
			}
		}
	}
	printf("%d\n" , dp[(1 << n) - 1]);
	int tot = 0;
	for(int i = (1 << n) - 1;i;i = pre[i]) {
		if(S[i])printf("%d " , S[i]);
	}
}