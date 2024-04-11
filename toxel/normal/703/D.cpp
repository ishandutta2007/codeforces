#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))

const int N = 1000010;

int c[N], a[N], ans[N], pre[N];
std::map <int, int> last;
std::pair <std::pair <int, int>, int> p[N];
int n, m;

void add(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] ^= value;
	}
}

int query(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret ^= c[sit];
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
	scanf("%d", &m);
	for (int i = 0, x, y; i < m; ++ i){
		scanf("%d%d", &x, &y);
		p[i] = {{y, x}, i};
	}
	std::sort(p, p + m);
	for (int i = 0, now = 0; i < m; ++ i){
		while (now < p[i].first.first){
			++ now;
			if (!last.count(a[now])){
				last[a[now]] = now;
				add(now, a[now]);
			}
			else{
				add(last[a[now]], a[now]);
				last[a[now]] = now;
				add(now, a[now]);
			}
		}
		ans[p[i].second] = pre[p[i].first.first] ^ pre[p[i].first.second - 1] ^ query(p[i].first.first) ^ query(p[i].first.second - 1);
	}
	for (int i = 0; i < m; ++ i){
		printf("%d\n", ans[i]);
	}
	return 0;
}