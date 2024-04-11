#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

char s[N][N], t[N][N];

string S, T;

int n, m, L[N], R[N], Len[N];

bool checkL(void) {
	for(int i = 1; i <= n; ++ i) if(R[i]) if(L[i] == 1) return 0;
	char c = ' ';
	for(int i = 1; i <= n; ++ i) {
		if(R[i]) {
			if(c == ' ') c = s[i][L[i] - 1];
			else if(c != s[i][L[i] - 1]) return 0;
		}
	}
	for(int i = 1; i <= n; ++ i) if(R[i]) -- L[i];
	return 1;
}

bool checkR(void) {
	for(int i = 1; i <= n; ++ i) if(R[i] == Len[i]) return 0;
	char c = ' ';
	for(int i = 1; i <= n; ++ i) {
		if(R[i]) {
			if(c == ' ') c = s[i][R[i] + 1];
			else if(c != s[i][R[i] + 1]) return 0;
		}
	}
	for(int i = 1; i <= n; ++ i) if(R[i]) ++ R[i];
	return 1;
}

int l = 0, ne[N];
char who[N];

int KMP(char *s, int ls, char *t, int lt) {
	ne[0] = -1;
	for(int i = 1; i <= ls; ++ i) {
		int t = ne[i - 1];
		while(t != -1 && s[t + 1] != s[i]) t = ne[t];
		ne[i] = t + 1;
	}
	int now = 0;
	for(int i = 1; i <= lt; ++ i) {
		while(now != -1 && s[now + 1] != t[i]) now = ne[now];
		++ now;
		if(now == ls) {
			return i;
		}
	}
	return 0;
}

bool pd(string S) {
	l = S.length();
	for(int i = 0; i < l; ++ i) who[i + 1] = S[i];
	who[l + 1] = '#';
	for(int i = 1; i <= n; ++ i) 
	if(R[i]) {
		if(KMP(who, l, s[i], Len[i]) != R[i]) {
			return 0;
		}
	}
	else if(KMP(who, l, s[i], Len[i])) return 0;
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) 
	scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++ i)
	scanf("%s", t[i] + 1);
	int last = 0;
	for(int i = 1; i <= n; ++ i) {
		int len = strlen(s[i] + 1);
		Len[i] = len;
		L[i] = len + 1, R[i] = 0;
		for(int j = 1; j <= len; ++ j) {
			if(s[i][j] != t[i][j])
			L[i] = min(L[i], j), 
			R[i] = max(R[i], j);
		}
		if(!R[i]) continue;
		if(last) {
			if(R[last] - L[last] != R[i] - L[i]) {
				puts("NO");
				return 0;
			}
			for(int j = L[i]; j <= R[i]; ++ j)
			if(s[i][j] != s[last][j - L[i] + L[last]] || t[i][j] != t[last][j - L[i] + L[last]]) 
			return 0 * puts("NO");
		}
		last = i;
		continue;
	}
	if(!last) {
		puts("LSKAKIOI");
		puts("ZRFAKIOI");
		return 0;
	}
	
	while(L[last] > 1 && checkL());
	while(R[last] < Len[last] && checkR());
	S = "";
	for(int i = L[last]; i <= R[last]; ++ i)
	S += s[last][i], T += t[last][i];
	if(pd(S)) {
		puts("YES");
		cout << S << endl;
		cout << T << endl;
		return 0;
	}
	else puts("NO");
}