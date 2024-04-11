/*
 * Author       : YangDavid
 * Created Time : 2020.10.05 21:48:42
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename... Args> auto ndim(size_t sz0, Args&&... args) {
    if constexpr(sizeof...(args) == 1) return vector(sz0, args...);
    else return vector(sz0, ndim(args...));
}

const int MAXN = 1000200;
int vis[MAXN], pre[MAXN];
vector<int> prime;
int main() {
	for(int i = 2; i < MAXN; ++i) {
		pre[i] = pre[i - 1];
		if(!vis[i]) prime.push_back(i), pre[i]++;
		for(auto j : prime) {
			if(i*j >= MAXN) break;
			vis[i*j] = true;
			if(i%j == 0) break;
		}
	}
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		printf("%d\n", pre[n] - pre[int(sqrt(n))] + 1);
	}

    return 0;
}