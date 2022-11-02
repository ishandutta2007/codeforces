#include <cstdio>
#include <cstring>
const int MAXN = 1000000;
const int MOD = int(1E9) + 7;
struct node{
	int len, dif, f;
	node *slk, *ch[26], *fa;
}pl[MAXN + 5], *rt1, *rt2, *ncnt;
node *nd[MAXN + 5];
void build(char *S, int len) {
	rt1 = ncnt = pl, rt2 = (++ncnt);
	rt2->fa = rt1, rt1->len = -1, rt2->len = 0;
	node *pre = rt1;
	for(int i=0;i<len;i++) {
		while( S[i] != S[i - pre->len - 1] )
			pre = pre->fa;
		if( pre->ch[S[i] - 'a'] == NULL ) {
			node *q = (++ncnt);
			q->len = pre->len + 2;
			if( pre == rt1 )
				q->fa = rt2;
			else {
				node *p = pre->fa;
				while( S[i] != S[i - p->len - 1 ] )
					p = p->fa;
				q->fa = p->ch[S[i] - 'a'];
			}
			q->dif = q->len - q->fa->len;
			q->slk = (q->dif == q->fa->dif ? q->fa->slk : q->fa);
			pre->ch[S[i] - 'a'] = q;
		}
		nd[i+1] = pre = pre->ch[S[i] - 'a'];
	}
}
char s[MAXN + 5], t[MAXN + 5];
int dp[MAXN + 5];
int main() {
	scanf("%s", s);
	int len = strlen(s);
	for(int i=0;i<len/2;i++)
		t[(i<<1) + 1] = s[i], t[(i<<1|1) + 1] = s[len-i-1];
	build(t + 1, len);
	dp[0] = 1;
	for(int i=1;i<=len;i++) {
		node *p = nd[i];
		while( p != rt2 ) {
			p->f = dp[i - p->slk->len - p->dif];
			if( p->slk != p->fa )
				p->f = (p->f + p->fa->f) % MOD;
			dp[i] = (dp[i] + p->f) % MOD;
			p = p->slk;
		}
		if( i & 1 ) dp[i] = 0;
	}
	printf("%d\n", dp[len]);
}