#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

const double eps = 1e-9;

struct Vec {
	int x, y;
	void input(void) {
		scanf("%lld%lld", &x, &y);
	}
	
	friend Vec operator + (Vec a, Vec b) {
		return (Vec){a.x + b.x, a.y + b.y};
	}
	
	friend Vec operator - (Vec a, Vec b) {
		return (Vec) {a.x - b.x, a.y - b.y};
	}
	
	friend int operator ^ (Vec a, Vec b) {
		return a.x * b.y - b.x * a.y;	
	}
	
	friend int operator * (Vec a, Vec b) {
		return a.x * b.x + a.y * b.y;
	}
	
	friend bool operator < (Vec a, Vec b) {
		return a.x < b.x;
	}
}P[N];

struct NODE {
	int x, y;
	double ang;
	friend bool operator < (NODE a, NODE b) {
		return a.ang < b.ang;
	}
}L[2000 * 2000];

int n, m, s, tot;

int Ra, Rb, who[N], pos[N];

int calc(int x) {
	return abs((P[Ra] - P[x]) ^ (P[Rb] - P[x]));
}

bool cmp(int x, int y) {
	if(P[x].y != P[y].y) P[x].y < P[y].y;
	return P[x].x < P[y].x;
}

void out(int a, int b, int c) {
	puts("Yes");
	cout << P[a].x << " " << P[a].y << endl;
	cout << P[b].x << " " << P[b].y << endl;
	cout << P[c].x << " " << P[c].y << endl;
}

main(void) {
	cin >> n >> s; s *= 2;
	for(int i = 1; i <= n; ++ i) P[i].input();
	sort(P + 1, P + n + 1);
	for(int i = 1; i <= n; ++ i) {
		for(int j = i + 1; j <= n; ++ j) {
			Vec cxt = P[j] - P[i];
			L[++ tot] = (NODE){i, j, atan2(cxt.y, cxt.x)};
		}
	}
	sort(L + 1, L + tot + 1);
	
	Ra = L[1].x, Rb = L[1].y;
	
	for(int i = 1; i <= n; ++ i) who[i] = i;
	sort(who + 1, who + n + 1, cmp);
	
	for(int i = 1; i <= n; ++ i) pos[who[i]] = i;
	
	int la = 0, lb = 0;
	
	for(int i = 1; i <= tot; ++ i) {
		if(la)swap(who[pos[la]], who[pos[lb]]), swap(pos[la], pos[lb]);
		Ra = L[i].x, Rb = L[i].y;
		int A = pos[Ra], B = pos[Rb];
		if(A > B) swap(A, B);
		int l = 1, r = A - 1, res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(who[mid]) <= s) {
				res = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		if(calc(who[res]) == s) {
			out(L[i].x, L[i].y, who[res]);
			return 0;
		}
		l = B + 1, r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(who[mid]) <= s) {
				res = mid; l = mid + 1;
			}
			else r = mid - 1;
		}
		if(calc(who[res]) == s) {
			out(L[i].x, L[i].y, who[res]);
			return 0;
		}		
		la = L[i].x, lb = L[i].y;
	}
	puts("No");
}