#include<bits/stdc++.h>

const int N = 100010;
inline int lowbit(int n){return n & -n;}

struct Query{
	int type, time, id;
	
	Query (int type = 0, int time = 0, int id = 0):type(type), time(time), id(id){}
};

int c[N], a[N], t[N], x[N];
int num[N], ans[N];
std::vector <Query> vec[N];

void add(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] += value;
	}
}

int query(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[sit];
	}
	return ret;
}

int main(){
	memset(ans, -1, sizeof(ans));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d%d", &a[i], &t[i], &x[i]);
	}
	for (int i = 0; i < n; ++ i){
		num[i] = t[i];
	}
	std::sort(num, num + n);
	int cnt = std::unique(num, num + n) - num;
	for (int i = 0; i < n; ++ i){
		t[i] = std::lower_bound(num, num + cnt, t[i]) - num + 1;
	}
	for (int i = 0; i < n; ++ i){
		num[i] = x[i];
	}
	std::sort(num, num + n);
	cnt = std::unique(num, num + n) - num;
	for (int i = 0; i < n; ++ i){
		x[i] = std::lower_bound(num, num + cnt, x[i]) - num;
	}
	for (int i = 0; i < n; ++ i){
		vec[x[i]].push_back(Query(a[i], t[i], i));
	}
	for (int i = 0; i < N; ++ i){
		for (auto u : vec[i]){
			if (u.type == 3){
				ans[u.id] = query(u.time);
			}
			else{
				add(u.time, u.type == 1 ? 1 : -1);
			}
		}
		for (auto u : vec[i]){
			if (u.type != 3){
				add(u.time, u.type == 1 ? -1 : 1);
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		if (~ans[i]){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}