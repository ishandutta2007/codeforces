#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5000000;

void solve1(char *S) {
	int lenS = strlen(S);
	for(int i=0,j=lenS-1;i<j;i++,j--)
		if( S[i] < S[j] ) break;
		else if( S[i] > S[j] ) {
			for(i=0,j=lenS-1;i<j;i++,j--)
				swap(S[i], S[j]);
			break;
		}
	puts(S);
}

void lyndon(char *S, int *f, int lenS) {
	int cnt = 0;
	for(int i=0;i<lenS;i++) f[i] = 0;
	for(int i=0;i<lenS;) {
		int j = i, k = i + 1;
		while( k < lenS && S[j] <= S[k] )
			j = (S[j] == S[k] ? j + 1 : i), k++;
		int t = k - j; cnt++;
		while( i + t - 1 < k )
			f[i + t - 1] = cnt, i += t;
	}
}

void algorithmZ(char *S, int *f, int lenS) {
	f[0] = lenS; int mx = 0, ps = 0;
	for(int i=1;i<lenS;i++) {
		f[i] = (i <= mx ? min(mx - i + 1, f[i - ps]) : 0);
		while( S[f[i]] == S[i+f[i]] ) f[i]++;
		if( i + f[i] - 1 > mx ) mx = i + f[i] - 1, ps = i;
	}
}

char ans[MAXN + 5], T[2*MAXN + 5]; int f[2*MAXN + 5];
int cmp(int l, int r) {
	int p = f[l];
	if( p >= r - l + 1 ) return 0;
	else return (T[l + p] < T[p] ? -1 : 1);
}// (s[l, r] == s[0, r-l] ? 0 : (s[l, r] < s[0, r-l] ? -1 : 1))
bool cmp2(char *S, char *T, int n) {
	for(int i=0;i<n;i++) {
		if( S[i] < T[i] ) return true;
		else if( S[i] > T[i] ) return false;
	}
	return true;
}// S < T
void update(char *T, int lenS) {
	if( cmp2(T, ans, lenS) ) for(int i=0;i<lenS;i++) ans[i] = T[i];
}
int get(int x) {
	int p; for(p = x - 1; p >= 0 && f[p] == 0; p--);
	return p;
}

void update2(char *S, int x, int lenS) {
	for(int i=0;i<x;i++) T[i] = S[x-i-1];
	for(int i=x;i<lenS;i++) T[i] = S[i];
	update(T, lenS);
	for(int i=x,j=lenS-1;i<j;i++,j--) swap(T[i], T[j]);
	update(T, lenS);
}

void solve2(char *S) {
	int lenS = strlen(S);
	for(int i=0;i<lenS;i++) ans[i] = S[i];
	
	for(int i=0;i<lenS;i++) T[lenS-i-1] = S[i], T[lenS+i+1] = S[i];
	algorithmZ(T, f, 2*lenS+1);
	int pos = 0;
	for(int i=1;i<lenS-1;i++) {
		int t = cmp(lenS + 1 + pos + 1, lenS + 1 + i);
		if( t == 0 ) {
			if( cmp(i - pos, lenS - pos - 2) == 1 ) pos = i;
		}
		else if( t == -1 ) pos = i;
	}
	for(int i=0;i<lenS;i++) T[i] = S[i];
	for(int i=pos+1,j=lenS-1;i<j;i++,j--) swap(T[i], T[j]);
	update(T, lenS);
	
	for(int i=0;i<lenS;i++) T[lenS-i-1] = S[i];
	lyndon(T, f, lenS);
	int tmp = get(lenS - 1);
	while( tmp >= 0 && f[tmp] == f[lenS - 1] ) tmp = get(tmp);
	update2(S, lenS - tmp - 1, lenS);
	if( tmp >= 0 ) {
		int p = get(tmp);
		while( p >= 0 && f[p] == f[tmp] ) p = get(p);
		update2(S, lenS - p - 1, lenS);
	}
	puts(ans);
}

void print(int l, int r) {
	for(int i=l;i<=r;i++)
		putchar(T[i]);
}

char S[MAXN + 5];
int main() {
	int k; scanf("%s%d", S, &k);
	if( k == 1 ) solve1(S);
	else {
		int lenS = strlen(S);
		for(int i=0;i<lenS;i++) T[lenS-i-1] = S[i];
		lyndon(T, f, lenS);
		int lst = lenS - 1, len = 0, tmp = 0;
		while( k >= 2 && lst >= 0 ) {
			int p = get(lst);
			if( !(len == 1 && lst - p == 1) && !(f[lst] == tmp)  ) {
				if( k == 2 ) break;
				k--;
			}
			print(p + 1, lst);
			len = lst - p, tmp = f[lst], lst = p;
		}
		if( lst >= 0 ) solve2(S + (lenS - lst - 1));
	}
}