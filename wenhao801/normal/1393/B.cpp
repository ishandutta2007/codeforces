#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 500500;

struct Tree {
	int ls, rs;
	int val, rnd;
	int siz;
} tree[MAXN];
int root, top = 0;

int newnode (int x) { ++top; tree[top].val = x, tree[top].siz = 1, tree[top].rnd = rand(); return top; }  
void pushup (int x) { tree[x].siz = tree[tree[x].ls].siz + tree[tree[x].rs].siz + 1; }

void split (int now, int k, int &x, int &y) {
	if (now == 0) { x = y = 0; return; }
	if (tree[now].val <= k) x = now, split(tree[now].rs, k, tree[now].rs, y);
	else y = now, split(tree[now].ls, k, x, tree[now].ls);
	pushup(now);
}

int merge (int x, int y) {
	if (!x || !y) return x + y;
	if (tree[x].rnd < tree[y].rnd) { tree[x].rs = merge(tree[x].rs, y); pushup(x); return x; }
	else { tree[y].ls = merge(x, tree[y].ls); pushup(y); return y; }
}

void ins (int x) {
	int r1 = 0, r2 = 0;
	split(root, x, r1, r2);
	root = merge(merge(r1, newnode(x)), r2);
}

void del (int x) {
	int r1 = 0, r2 = 0, r3 = 0;
	split(root, x, r2, r3);
	split(r2, x - 1, r1, r2);
	r2 = merge(tree[r2].ls, tree[r2].rs);
	r1 = merge(r1, r2); root = merge(r1, r3);
}

int rnk (int x) {
	int r1 = 0, r2 = 0;
	split(root, x - 1, r1, r2);
	int ret = tree[r1].siz + 1;
	root = merge(r1, r2);
    return ret;
}

int kth (int x, int k) {
    if (tree[tree[x].ls].siz >= k) return kth(tree[x].ls, k);
    if (k > tree[tree[x].ls].siz + 1) return kth(tree[x].rs, k - tree[tree[x].ls].siz - 1);
    return tree[x].val;
}

int pre (int k) {
    int r1 = 0, r2 = 0;
    split(root, k - 1, r1, r2);
    int now = r1;
    while (tree[now].rs) now = tree[now].rs;
    root = merge(r1, r2);
    return tree[now].val;
}

int suf (int k) {
    int r1 = 0, r2 = 0;
    split(root, k, r1, r2);
    int now = r2;
    while (tree[now].ls) now = tree[now].ls;
    root = merge(r1, r2);
    return tree[now].val;
}

int Max () {
    int now = root;
    while (tree[now].rs) now = tree[now].rs;
    return tree[now].val;
}

int buc[100100];

int main () {
	srand(time(NULL));
    int n = read();
    int i, j;
    for (i = 1; i <= n; i++ )++buc[read()];
    for (i = 1; i <= 100000; i++) ins(buc[i]);
    int q = read();
    while (q--) {
        char s[2]; cin >> s;
        int x = read();
        del(buc[x]);
        if (s[0] == '+') ++buc[x]; else --buc[x];
        ins(buc[x]);
        int a = -1, b = -1, c = -1;
        if (!tree[root].siz) { puts("NO"); continue; }
        int tmp = Max();
        if (tmp < 4) { puts("NO"); continue; }
        if (tmp >= 8) { puts("YES"); continue; }
        else {
            a = tmp; del(a);
            if (!tree[root].siz) { puts("NO"); ins(a); continue; }
            tmp = Max();
            if (a >= 6 && tmp >= 2) { puts("YES"); }
            else if (a >= 6 && tmp < 2) { puts("NO"); }
            else if (a >= 4 && tmp >= 4) { puts("YES"); }
            else {
                b = tmp; del(b);
                
                if (!tree[root].siz) { puts("NO"); ins(a); ins(b); continue; }
                 tmp = Max();
                if (tmp >= 2) puts("YES");
                else puts("NO");
            }
            if (a != -1) ins(a);
            if (b != -1) ins(b);
        }
    }
	return 0;
}