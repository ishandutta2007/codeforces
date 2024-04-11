#include<bits/stdc++.h>
#define ll long long

const int MAXN = 100010;
const int MAX = 60;
const ll N = 1ll << MAX;

class segment{
public:
	int sum, lazy;
	segment *child[2];
	
	segment():sum(0), lazy(0){memset(child, 0, sizeof(child));}
	int getsum(){return this ? sum : 0;}
	int getlazy(){return this ? lazy : 0;}
	segment *getchild(int type){return this ? child[type] : NULL;}
	void setsum(int sum){if (this) this -> sum = sum;}
	void setlazy(int lazy){if (this) this -> lazy = lazy;}
};

segment *segpool;
int nowsize;

segment *newseg(){
	if (!nowsize){
		segpool = new segment[MAXN];
		nowsize += MAXN;
	}
	return segpool + -- nowsize;
}

void push(segment *root){
	if (root -> getlazy()){
		root -> getchild(0) -> setsum(0);
		root -> getchild(1) -> setsum(0);
		root -> getchild(0) -> setlazy(1);
		root -> getchild(1) -> setlazy(1);
		root -> setlazy(0);
	}
}

void pull(segment *root){
	if (root){
		root -> sum = root -> getchild(0) -> getsum() + root -> getchild(1) -> getsum();
	}
}

void add(segment *&root, ll l, ll r, ll sit, int value){
	if (!root){
		root = newseg();
	}
	root -> sum += value;
	if (l >= r){
		return;
	}
	push(root);
	ll mid = l + r >> 1;
	if (sit <= mid){
		add(root -> child[0], l, mid, sit, value);
	}
	else{
		add(root -> child[1], mid + 1, r, sit, value);
	}
}

int count(segment *root, ll sit){
	for (int i = MAX - 1; ~i; -- i){
		push(root);
		root = root -> getchild(sit >> i & 1);
	}
	return root -> getsum();
}

void del(segment *root, ll l, ll r, ll ql, ll qr){
	if (l >= ql && r <= qr){
		root -> setsum(0);
		root -> setlazy(1);
		return;
	}
	push(root);
	if (l >= r){
		return;
	}
	ll mid = l + r >> 1;
	if (ql <= mid){
		del(root -> getchild(0), l, mid, ql, qr);
	}
	if (qr > mid){
		del(root -> getchild(1), mid + 1, r, ql, qr);
	}
	pull(root);
}

int query(segment *root, ll p){
	int ret = 0;
	for (int i = MAX - 1; ~i; -- i){
		push(root);
		if (p >> i & 1){
			ret += root -> getchild(0) -> getsum();
			root = root -> getchild(1);
		}
		else{
			root = root -> getchild(0);
		}
	}
	return ret;
}

ll querymin(segment *root, ll l, ll r, ll ql, ll qr){
	if (l >= ql && r <= qr){
		if (!root -> getsum()){
			return LLONG_MAX;
		}
		if (l == r){
			return l;
		}
	}
	push(root);
	ll mid = l + r >> 1;
	if (ql <= mid){
		ll ret = querymin(root -> getchild(0), l, mid, ql, qr);
		if (ret < LLONG_MAX){
			return ret;
		}
	}
	if (qr > mid){
		ll ret = querymin(root -> getchild(1), mid + 1, r, ql, qr);
		if (ret < LLONG_MAX){
			return ret;
		}
	}
	return LLONG_MAX;
}

int main(){
	int test;
	scanf("%d", &test);
	segment *root = NULL;
	while (test --){
		int op;
		ll l, r;
		scanf("%d%I64d%I64d", &op, &l, &r);
		++ r;
		if (op == 1){
			int cnt1 = query(root, l), cnt2 = query(root, r);
			if (count(root, l)){
				if (cnt1 & 1){
					add(root, 0, N - 1, l, -1);
				}
			}
			else{
				if (!(cnt1 & 1)){
					add(root, 0, N - 1, l, 1);
				}
			}
			if (count(root, r)){
				if (!(cnt2 & 1)){
					add(root, 0, N - 1, r, -1);
				}
			}
			else{
				if (!(cnt2 & 1)){
					add(root, 0, N - 1, r, 1);
				}
			}
			del(root, 0, N - 1, l + 1, r - 1);
		}
		else if (op == 2){
			int cnt1 = query(root, l), cnt2 = query(root, r);
			if (count(root, l)){
				if (!(cnt1 & 1)){
					add(root, 0, N - 1, l, -1);
				}
			}
			else{
				if (cnt1 & 1){
					add(root, 0, N - 1, l, 1);
				}
			}
			if (count(root, r)){
				if (cnt2 & 1){
					add(root, 0, N - 1, r, -1);
				}
			}
			else{
				if (cnt2 & 1){
					add(root, 0, N - 1, r, 1);
				}
			}
			del(root, 0, N - 1, l + 1, r - 1);
		}
		else{
			add(root, 0, N - 1, l, count(root, l) ? -1 : 1);
			add(root, 0, N - 1, r, count(root, r) ? -1 : 1);
		}
		ll x1 = querymin(root, 0, N - 1, 0, N - 1);
		if (x1 > 1){
			printf("1\n");
		}
		else{
			printf("%I64d\n", querymin(root, 0, N - 1, x1 + 1, N - 1));
		}
	}
	return 0;
}