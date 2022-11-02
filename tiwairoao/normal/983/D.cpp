#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = (1<<30);
const int MAXN = 100000;
struct node{
	int le, ri;
	set<int>Set;
	int mx, mn;
}tree[24*MAXN + 5];
bool tag[MAXN + 5];
void pushup(int x) {
	if( tree[x].le == tree[x].ri )
		tree[x].mx = tree[x].mn = *tree[x].Set.rbegin();
	else {
		tree[x].mn = max(*tree[x].Set.rbegin(), min(tree[x<<1].mn, tree[x<<1|1].mn));
		tree[x].mx = max(*tree[x].Set.rbegin(), max(tree[x<<1].mx, tree[x<<1|1].mx));
	}
	if( tree[x].mx < tree[x].mn ) tree[x].mx = -1;
	if( tree[x].mx != -1 && tag[tree[x].mx] ) tree[x].mx = -1;
}
void build(int x, int l, int r) {
	tree[x].le = l, tree[x].ri = r;
	tree[x].mx = tree[x].mn = 0;
	tree[x].Set.clear(); tree[x].Set.insert(0);
	if( l == r ) return ;
	int mid = (l + r) >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
}
void modify(int x, int l, int r, int k, int type) {
	if( l > tree[x].ri || r < tree[x].le )
		return ;
	if( l <= tree[x].le && tree[x].ri <= r ) {
		if( type ) tree[x].Set.insert(k);
		else tree[x].Set.erase(k);
		pushup(x);
		return ;
	}
	modify(x<<1, l, r, k, type);
	modify(x<<1|1, l, r, k, type);
	pushup(x);
}
void update(int x, int l, int r) {
	if( l > tree[x].ri || r < tree[x].le )
		return ;
	if( l <= tree[x].le && tree[x].ri <= r ) {
		pushup(x);
		return ;
	}
	update(x<<1, l, r);
	update(x<<1|1, l, r);
	pushup(x);
}
int N;
int Xa[MAXN + 5], Xb[MAXN + 5], Ya[MAXN + 5], Yb[MAXN + 5];
int dct[2][6*MAXN + 5], dcnt[2];
void discrete() {
	for(int i=0;i<2;i++)
		sort(dct[i]+1, dct[i]+dcnt[i]+1);
	for(int i=0;i<2;i++)
		dcnt[i] = unique(dct[i]+1, dct[i]+dcnt[i]+1) - dct[i] - 1;
	for(int i=1;i<=N;i++) {
		Xa[i] = lower_bound(dct[0]+1, dct[0]+dcnt[0]+1, Xa[i]) - dct[0];
		Xb[i] = lower_bound(dct[0]+1, dct[0]+dcnt[0]+1, Xb[i]) - dct[0];
		Ya[i] = lower_bound(dct[1]+1, dct[1]+dcnt[1]+1, Ya[i]) - dct[1];
		Yb[i] = lower_bound(dct[1]+1, dct[1]+dcnt[1]+1, Yb[i]) - dct[1];
	}
}
void insert_dct(int val, int type) {
	dct[type][++dcnt[type]] = val;
}
struct query{
	int le, ri, num;
	bool type;
	query(int _l=0, int _r=0, int _n=0, bool _t=0):le(_l), ri(_r), num(_n), type(_t){}
};
vector<query>vec[6*MAXN + 5];
int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%d%d%d%d", &Xa[i], &Ya[i], &Xb[i], &Yb[i]);
		Xb[i]--, Yb[i]--;
		insert_dct(Xa[i], 0); insert_dct(Xa[i]+1, 0); insert_dct(Xa[i]-1, 0);
		insert_dct(Xb[i], 0); insert_dct(Xb[i]+1, 0); insert_dct(Xb[i]-1, 0);
		insert_dct(Ya[i], 1); insert_dct(Ya[i]+1, 1); insert_dct(Ya[i]-1, 1);
		insert_dct(Yb[i], 1); insert_dct(Yb[i]+1, 1); insert_dct(Yb[i]-1, 1);
	}
	discrete();
	for(int i=1;i<=N;i++) {
		vec[Xa[i]].push_back(query(Ya[i], Yb[i], i, 1));
		vec[Xb[i]+1].push_back(query(Ya[i], Yb[i], i, 0));
	}
	build(1, 1, dcnt[1]); Ya[0] = 1; Yb[0] = dcnt[1];
	for(int i=1;i<=dcnt[0];i++) {
		for(int j=0;j<vec[i].size();j++)
			modify(1, vec[i][j].le, vec[i][j].ri, vec[i][j].num, vec[i][j].type);
		while( tree[1].mx != -1 ) {
			tag[tree[1].mx] = true;
			update(1, Ya[tree[1].mx], Yb[tree[1].mx]);
		}
	}
	int ans = 0;
	for(int i=0;i<=N;i++)
		if( tag[i] ) ans++;
	printf("%d\n", ans);
}