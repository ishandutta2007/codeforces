#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
char s[MAXN];

int preA[MAXN], preP[MAXN];
int nxtA[MAXN], nxtP[MAXN];
int umi;
int vis[MAXN];
int f[MAXN];

int calc(int st, int dir, int lim){
	int tm = 0;
	for (int i = st, j = 0; i != lim; i += dir, j++)
		if (s[i] == '*'){
			tm = max(tm, j);
		}
	return tm;
}

int notA(int l, int r) {
	// [l, r]
	l = max(l, 1);
	r = min(r, n);
	if (l > r) return 1;
	if (nxtA[l - 1] > r) return 1;
	return 0;
}

int check(int L){
	// cout << "L ===== " << L << endl;
	f[0] = 0;
	for (int i = 1; i <= n; i++) if (s[i - 1] == 'P') {
		int pp = preP[i];
		f[i] = f[pp];
		if (notA(f[pp] + 1, i - L - 1)) f[i] = max(f[i], i);
		if (notA(f[pp] + 1, i - 1)) f[i] = max(f[i], i + L);
		if (pp > 0) {
			if (notA(f[preP[pp]] + 1, i - L - 1)) f[i] = max(f[i], pp + L);
		}
	}
	// for (int i = 0; i <= n; i++) 
	// 	cout << f[i] << ' '; cout << endl;
	if (notA(f[preP[n + 1]] + 1, n)) return 1;
	else return 0;
}

void solve(int casi){
	scanf("%d", &n);
	scanf("%s", s);
	int cnt = 0, ct2 = 0;
	for (int i = 0; i < n; i++){
		cnt += (s[i] == 'P');
		ct2 += (s[i] == '*');
	}
	if (cnt == 1){
		int o = 0, pp;
		for (int i = 0; i < n; i++)
			if (s[i] == 'P'){
				pp = i;
				break;
			}
			else{
				o += (s[i] == '*');
			}
		if (o > ct2 - o){
			printf("%d %d\n", o, calc(pp, -1, -1));
		}
		else if (o < ct2 - o){
			printf("%d %d\n", ct2 - o, calc(pp, 1, n));
		}
		else{
			printf("%d %d\n", o, min(calc(pp, -1, -1), calc(pp, 1, n)));
		}
		return ;
	}
	printf("%d ", ct2);
	
	preP[0] = preA[0] = preP[1] = preA[1] = 0;
	nxtP[n + 1] = nxtA[n + 1] = nxtP[n] = nxtA[n] = n + 1;
	for (int i = 2; i <= n + 1; i++){
		if (s[i - 2] == 'P')
			preP[i] = i - 1;
		else
			preP[i] = preP[i - 1];
		if (s[i - 2] == '*')
			preA[i] = i - 1;
		else
			preA[i] = preA[i - 1];
	}
	for (int i = n - 1; i >= 0; i--){
		if (s[i] == 'P')
			nxtP[i] = i + 1;
		else
			nxtP[i] = nxtP[i + 1];
		if (s[i] == '*')
			nxtA[i] = i + 1;
		else
			nxtA[i] = nxtA[i + 1];
	}
	
	int l = 0, r = n - 1;
	umi = 0;
	while(l + 1 < r){
		umi++;
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	printf("%d\n", r);
}

int main(){
	int T = 1;
	for(int i = 1; i <= T; i++){
		solve(i);
	}
	return 0;
}