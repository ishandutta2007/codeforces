#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2000000;

namespace SAM{
	int cnt[MAXN + 5]; bool tag[MAXN + 5];
	int ch[26][MAXN + 5], fa[MAXN + 5], len[MAXN + 5], root, lst, ncnt;
	void init() {
		ncnt = lst = root = 1, len[root] = fa[root] = 0;
		for(int i=0;i<26;i++) ch[i][root] = 0;
		cnt[root] = 0;
	}
	int newnode() {
		int p = (++ncnt); len[p] = fa[p] = 0;
		for(int i=0;i<26;i++) ch[i][p] = 0;
		cnt[p] = 1; return p;
	}
	int clone(int q) {
		int nq = newnode(); fa[nq] = fa[q];
		for(int i=0;i<26;i++) ch[i][nq] = ch[i][q];
		cnt[nq] = 0; return nq;
	}
	void extend(int c) {
		int p = lst, cur = newnode(); len[cur] = len[lst] + 1, lst = cur;
		while( p && !ch[c][p] )
			ch[c][p] = cur, p = fa[p];
		if( !p ) fa[cur] = root;
		else {
			int q = ch[c][p];
			if( len[p] + 1 == len[q] ) fa[cur] = q;
			else {
				int nq = clone(q); len[nq] = len[p] + 1;
				fa[cur] = fa[q] = nq;
				while( p && ch[c][p] == q )
					ch[c][p] = nq, p = fa[p];
			}
		}
	}
	int a[MAXN + 5], b[MAXN + 5];
	void get() {
		for(int i=1;i<=ncnt;i++) b[i] = 0;
		for(int i=1;i<=ncnt;i++) b[len[i]]++;
		for(int i=1;i<=ncnt;i++) b[i] += b[i - 1];
		for(int i=1;i<=ncnt;i++) a[b[len[i]]--] = i;
		for(int i=ncnt;i>=2;i--) cnt[fa[a[i]]] += cnt[a[i]];
	}
	
	ll solve(char *S) {
		ll ret = 0; int lenS = strlen(S), nw = root, mxl = 0;
		for(int i=0;i<lenS;i++) {
			while( nw && !ch[S[i] - 'a'][nw] )
				nw = fa[nw];
			mxl = min(mxl, len[nw]), nw = (nw ? ch[S[i] - 'a'][nw] : root), mxl++;
			if( mxl >= lenS ) {
				while( len[fa[nw]] >= lenS ) nw = fa[nw]; mxl = min(mxl, len[nw]);
				if( !tag[nw] ) ret += cnt[nw], tag[nw] = true;
			}
		}
		for(int i=0;i<lenS;i++) {
			while( nw && !ch[S[i] - 'a'][nw] )
				nw = fa[nw];
			mxl = min(mxl, len[nw]), nw = (nw ? ch[S[i] - 'a'][nw] : root), mxl++;
			if( mxl >= lenS ) {
				while( len[fa[nw]] >= lenS ) nw = fa[nw]; mxl = min(mxl, len[nw]);
				if( !tag[nw] ) ret += cnt[nw], tag[nw] = true;
			}
		}
		
		nw = root;
		for(int i=0;i<lenS;i++) {
			while( nw && !ch[S[i] - 'a'][nw] )
				nw = fa[nw];
			mxl = min(mxl, len[nw]), nw = (nw ? ch[S[i] - 'a'][nw] : root), mxl++;
			if( mxl >= lenS ) {
				while( len[fa[nw]] >= lenS ) nw = fa[nw]; mxl = min(mxl, len[nw]);
				tag[nw] = false;
			}
		}
		for(int i=0;i<lenS;i++) {
			while( nw && !ch[S[i] - 'a'][nw] )
				nw = fa[nw];
			mxl = min(mxl, len[nw]), nw = (nw ? ch[S[i] - 'a'][nw] : root), mxl++;
			if( mxl >= lenS ) {
				while( len[fa[nw]] >= lenS ) nw = fa[nw]; mxl = min(mxl, len[nw]);
				tag[nw] = false;
			}
		}
		
		return ret;
	}
}

char s[MAXN + 5]; int lens;
int main() {
	scanf("%s", s), lens = strlen(s), SAM::init();
	for(int i=0;i<lens;i++) SAM::extend(s[i] - 'a');
	SAM::get();
	
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%s", s), printf("%lld\n", SAM::solve(s));
}