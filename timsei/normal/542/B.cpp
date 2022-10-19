#include<bits/stdc++.h>
using namespace std;
const int M = 1e7 + 5;

int n, t, pre = -1;

int mx[M], lc[M], rc[M], tag[M], sz = 0;

#define pii pair<int,int>
#define se second
#define fi first
priority_queue < pii > q;

void up(int x) {
	mx[x] = max(mx[lc[x]], mx[rc[x]]) + tag[x];
}

void upd(int &x, int l, int r, int who, int v){
	if(!x) x =  ++ sz;
	if(l == r){
		tag[x] = mx[x] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(who <= mid) upd(lc[x], l, mid, who, v);
	else upd(rc[x], mid + 1, r, who, v);
	up(x);
}

void add(int &x, int l, int r, int L, int R){
	if(!x) return;
	R = min(R, r); L = max(l, L);
	if(L > R) return;
	if(l == L && R == r){
		++ mx[x]; ++ tag[x];
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid)
	add(lc[x], l, mid, L, R);
	else if(L > mid)
	add(rc[x], mid + 1, r, L, R);
	else add(lc[x], l, mid, L, mid), add(rc[x], mid + 1, r, mid + 1, R);
	up(x);
}

int ask(int &x, int l, int r, int L, int R){
	if(!x) return 0;
	R = min(R, r); L = max(l, L);
	if(L > R) return 0;
	if (l == L && R == r) 
	return mx[x];
	int mid = (l + r) >> 1;
	if(R <= mid) return ask(lc[x], l, mid, L, R) + tag[x];
	else if(L > mid) return ask(rc[x], mid + 1, r, L, R) + tag[x];
	else return max(ask(lc[x], l, mid, L, mid), ask(rc[x], mid + 1, r, mid + 1, R)) + tag[x];
}
int rt;
int main(){
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; ++ i){
		int l, r;
		scanf("%d%d", &l, &r);
		l = max(0, l);
		q.push(make_pair(-r, -l));
		q.push(make_pair(-l, 1));
	}
	while (!q.empty()){
		int l = -q.top().se, r = -q.top().fi; 
		q.pop();
		if(l >= 0) add(rt, 0, 1e9, l, r);
		else{
			if(r == pre) continue;
			int u = ask(rt, 0, 1e9, pre, pre);
			int v = ask(rt, 0, 1e9, 0, r - t);
			if(l == -1 || u < v){
				pre = r;
				upd(rt, 0, 1e9, r, v);
				if(r + t <= 1e9)
					q.push(pii(-r - t, 2));
			}
		}
	}
	printf("%d\n", mx[1]);
}