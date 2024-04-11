#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int tree[401000];
	int n;
	segtree(int m):n(m) {}
	void upd(int idx, int val, int s = -1, int e = -1, int loc = 1) {
		if (s<0) {s = 0; e = n;}
		if (e<idx||idx<s) return;
		if (s==e) {
			tree[loc] += val;
			return;
		}
		int m = (s+e)>>1;
		upd(idx,val,s,m,loc*2);
		upd(idx,val,m+1,e,loc*2+1);
		tree[loc] = tree[loc*2]+tree[loc*2+1];
	}
	int getv(int S, int E, int s = -1, int e = -1, int loc = 1){
		if (s<0) {s = 0; e = n;}
		if (e<s||e<S||E<s) return 0;
		if (S<=s&&e<=E) return tree[loc];
		int m = (s+e)>>1;
		return getv(S,E,s,m,loc*2)+getv(S,E,m+1,e,loc*2+1);
	}
} *seg[11][11][5];

int n, q;
char str[100100]; char buf[15];
char tmp[5] = "ACGT";

int value(char ch) {
	int i;
	for (i=0;i<5;i++) if (tmp[i]==ch) return i;
	return -1;
}

int main() {
	int i, j, k;

	scanf("%s",str);
	n = strlen(str);
	for (i=1;i<=10;i++) {
		for (j=0;j<i;j++) {
			for (k=0;k<4;k++) seg[i][j][k] = new segtree(n/i+2);
		}
	}
	for (i=0;i<n;i++) {
		str[i] = (char)value(str[i]);
		for (j=1;j<=10;j++) {
			seg[j][i%j][str[i]]->upd(i/j,1);
		}
	}
	scanf("%d",&q);
	for (i=0;i<q;i++) {
		int a;
		scanf("%d",&a);
		if (a==1) {
			int x; char bf[3], ch;
			scanf("%d%s",&x,bf); --x;
			ch = bf[0];
			ch = (char)value(ch);
			if (str[x]==ch) continue;
			for (j=1;j<=10;j++) seg[j][x%j][str[x]]->upd(x/j,-1);
			for (j=1;j<=10;j++) seg[j][x%j][ch]->upd(x/j,1);
			str[x] = ch;
		}
		else {
			int l, r;
			scanf("%d%d%s",&l,&r,buf); --l; --r;
			int e = strlen(buf), res = 0;
			for (j=0;j<e;j++) {
				int tl = (l%e<=j)?(l/e):(l/e+1);
				int tr = (r%e>=j)?(r/e):(r/e-1);
				res += seg[e][j][value(buf[(j+e-l%e)%e])]->getv(tl,tr);
			}
			printf("%d\n",res);
		}
	}

    return 0;
}