#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 1123456;

int p10[N], inv[N], ct[20];
char s[N];
char s2[N]; int sn; bool any = false;
int beg, nx;

void deal_0(int i) {
	if(!any) {
		any = true;
		s2[sn++] = i + '0';
		ct[i]--;
		while(ct[0]) s2[sn++] = '0', ct[0]--;
		if(beg == 0) for(int j = 0; s[j]; j++) s2[sn++] = s[j];
	}
}

int bk[10];

int main() {
	int i, j, n;
	for(i = 1; i <= 1000000; i++) {
		p10[i] = 1 + p10[i / 10];
		inv[i + p10[i]] = i;
	}
	scanf("%s", s);
	for(i = 0; s[i]; i++)
		ct[s[i] - '0']++;
	n = i;
	scanf("%s", s);
	if(n == 2 && ct[0] == 1) { puts("0"); return 0; }
	for(i = 0; s[i]; i++) ct[s[i] - '0']--;
	for(i = 1; s[i] == s[i - 1]; i++);
	beg = s[0] - '0'; nx = s[i] - '0';
	if(!s[i]) nx = beg;
	for(int sz = inv[n]; sz; sz /= 10) ct[sz % 10]--;
	for(i = 0; i <= 9; i++) bk[i] = ct[i];
	for(i = 1; i <= 9; i++) {
		if(beg == i) {
			if(ct[i]) {
				if(ct[0]) {
					any = true;
					s2[sn++] = i + '0'; ct[i]--;
					while(ct[0]) s2[sn++] = '0', ct[0]--;
				}
				if(nx < beg) {
					for(j = 0; s[j]; j++) s2[sn++] = s[j];
					while(ct[i]) s2[sn++] = i + '0', ct[i]--;
				} else {
					while(ct[i]) s2[sn++] = i + '0', ct[i]--;
					for(j = 0; s[j]; j++) s2[sn++] = s[j];
				}
			} else {
				for(j = 0; s[j]; j++) s2[sn++] = s[j];
				any = true;
				while(ct[0]) s2[sn++] = '0', ct[0]--;
			}
		} else if(ct[i]) {
			deal_0(i);
			while(ct[i]) s2[sn++] = i + '0', ct[i]--;
		}
	}
	string S1 = s2;
	for(i = 0; i <= 9; i++) ct[i] = bk[i];
	sn = 0; any = false;
	for(i = 1; i <= 9; i++) {
		if(beg == i) {
			if(ct[i]) {
				if(ct[0]) {
					any = true;
					for(j = 0; s[j]; j++) s2[sn++] = s[j];
					while(ct[0]) s2[sn++] = '0', ct[0]--;
					while(ct[i]) s2[sn++] = i + '0', ct[i]--;
					continue;
				}
				if(nx < beg) {
					for(j = 0; s[j]; j++) s2[sn++] = s[j];
					while(ct[i]) s2[sn++] = i + '0', ct[i]--;
				} else {
					while(ct[i]) s2[sn++] = i + '0', ct[i]--;
					for(j = 0; s[j]; j++) s2[sn++] = s[j];
				}
			} else {
				for(j = 0; s[j]; j++) s2[sn++] = s[j];
				any = true;
				while(ct[0]) s2[sn++] = '0', ct[0]--;
			}
		} else if(ct[i]) {
			deal_0(i);
			while(ct[i]) s2[sn++] = i + '0', ct[i]--;
		}
	}
	string S2 = s2;
	puts(min(S1, S2).c_str());
}