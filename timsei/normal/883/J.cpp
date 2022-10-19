#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

#define int long long
#define lowbit(x) (x & (-x))

struct NODE {
	int up , Cost , col;
	friend bool operator < (NODE xxx , NODE yyy) {
		return xxx.up < yyy.up;
	}
}R[N];

struct Qian {
	int T , id;
	friend bool operator < (Qian xxx , Qian yyy) {
		return xxx.T > yyy.T;
	}
}A[N];

bool cmp(NODE xxx , NODE yyy) {
	return xxx.Cost < yyy.Cost;
}

int T[M] , n , m , col[N] , S[N] , all[N] , lst[N];
int fa[N];
bool cannot[N];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

int Si[N];

void add(int x , int v) {
//	cerr <<  x <<" "<< v << endl;
	for(int i = x;i < N;i += lowbit(i)) Si[i] += v;
}

int sum(int x) {
	int res = 0;
	for(int i = x;i;i -= lowbit(i)) res += Si[i];
	return res;
}

main(void) {
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> T[i];
		A[i].T = T[i]; A[i].id = i;
	}
	sort(A + 1 , A + n + 1);
	int mx = 1;
	for(int i = 1;i <= n;i ++) {
		if(A[i].id < mx) continue;
		for(int j = mx;j <= A[i].id;j ++) col[j] = A[i].id;
		mx = A[i].id + 1;
	}
//	for(int i = 1;i <= n;i ++) cerr << col[i] <<" "; puts("");
	for(int i = 1;i <= m;i ++) cin >> R[i].up; for(int i = 1;i <= m;i ++) cin >> R[i].Cost , R[i].col = 0;
//	for(int i = 1;i <= n;i ++) cerr << T[i] << " "; puts("");
	sort(R + 1 ,  R + m + 1);
	int now = n; while(col[now] != now) now --;
	for(int i = 1;i <= m;i ++) {
		if(R[i].up <= T[now]) {
			R[i].col = now;
		}
		else {
			while(T[now] < R[i].up) {
				now --;
				while(col[now] != now && now) now --;
				if(!now) break;
			}
			if(!now) break;
			i --;
		}
	}
//	for(int i = 1;i <= m;i ++) printf("%d " , R[i].col) ; puts("");
	for(int i = 1;i <= n;i ++) S[i] = S[i - 1] + T[i];
	int last = 0;
	for(int i = 1;i <= n;i ++) {
		if(i == col[i]) {
			all[i] = S[i] - S[last];
			lst[i] = last;
			last = i;
		}
		add(i , T[i]);
	}
//	for(int i = 1;i <= n;i ++) cerr << all[i] << " "<< lst[i] <<endl;
	sort(R + 1 , R + m + 1 , cmp);
//	for(int i = 1;i <= m;i ++) cerr <<R[i].Cost <<" "; puts("");
	for(int i = 1;i <= n;i ++) fa[i] = i;
	int ans = 0;
	for(int i = 1;i <= m;i ++) {
		if(!R[i].col || sum(R[i].col) < R[i].Cost) continue;
		ans ++;
		int now = getf(R[i].col);
		int St = R[i].Cost;
		while(1) {
			if(!now) break;
			while(!all[now] && now) {
				fa[getf(now)] = getf(lst[getf(now)]);
				now = getf(now);
			}
			if(all[now] >= St) {
				all[now] -= St; add(now , -St); St = 0;
				break;
			}
			else {
				add(now , -all[now]); St -= all[now];all[now] = 0;
				fa[now] = getf(lst[now]);
			}
			now = getf(now);
		}
	}
	cout << ans;
}