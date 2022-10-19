#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 400005;
const int M = N * 4;
const int Segment_Size = N * 4;

int fir[N] , ne[M] , to[M] , C[M] , x , y , z , cnt , in[N] , out[N], dfs_clock , Tr[N] , back[N] , idback[N] , id_tofa[N] , fa[N] , L[N] , R[N] , Tf[N]  , n , q ,pos[N];

void add(int x , int y ,int z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = z;
}

#define lc no << 1
#define rc no << 1 | 1
#define getmid int mid = (L[no] + R[no]) >> 1;

struct NODE {
	int lazy , Min;
};

NODE operator + (NODE xxx , NODE yyy) {
	NODE ret; ret.lazy = ret.Min = 0;
	ret.Min = min(xxx.Min , yyy.Min);
	return ret;
}

struct Segment_Tree {
	int L[Segment_Size] , R[Segment_Size];
	NODE info[Segment_Size];
	void build(int no , int l , int r) {
		L[no] = l; R[no] = r; 
		if(l == r) {
			info[no].Min = Tr[pos[l]] + back[pos[l]];
			info[no].lazy = 0;
			return;
		}
		getmid;
		build(lc , l , mid); build(rc , mid + 1 , r);
		info[no] = info[lc] + info[rc];
	}
	
	void pushdown(int no) {
		if(info[no].lazy) {
			info[lc].lazy += info[no].lazy;
			info[rc].lazy += info[no].lazy;
			info[lc].Min += info[no].lazy;
			info[rc].Min += info[no].lazy;
			info[no].lazy = 0;
		}
	}
	
	int query(int no , int l , int r) {
		if(L[no] == R[no]) {
			return info[no].Min;
		}
		pushdown(no);
		getmid;
		if(r <= mid) return query(lc , l , r);
		if(l > mid) return query(rc , l , r);
		return min(query(lc , l , mid) , query(rc , mid + 1, r));
	}
	
	void pushtag(NODE &xxx, int x) {
		xxx.lazy += x; xxx.Min += x;
	}
	
	void chg(int no , int l , int r , int x) {
		if(L[no] == R[no]) {
			pushtag(info[no] , x);
			return;
		}
		getmid;
		if(r <= mid) {
			chg(lc , l , r, x);
		}
		else if(l > mid) {
			chg(rc , l , r , x);
		}
		else {
			chg(lc , l , mid , x); chg(rc , mid + 1 , r , x);
		}
		info[no] = info[lc] + info[rc];
	}
};

Segment_Tree Seg;

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int idx[N];

void dfs(int x , int f) {
	fa[x] = f; idx[x] = L[x] = in[x] = ++ dfs_clock; pos[dfs_clock] = x;
	Foreachson(i , x) {
		int V = to[i];
		if(V == f) continue;
		id_tofa[i] = V;
		Tr[V] = Tr[x] + C[i];
		Tf[V] = C[i];
		dfs(V , x);
	}
	R[x] = out[x] = dfs_clock;
}

bool is_ancestor(int x , int y) {
	return ((in[x] <= in[y]) && (out[x] >= out[y]));
} 

void read(void) {
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n - 1;i ++) {
		int x , y , Val;
		scanf("%d%d%d",&x,&y,&Val);
		add(x , y , Val);
	}
	dfs(1 , 0);
	for(int i = 1;i <= n;i ++) {
//		cerr<<i<<" "<<L[i] <<" "<<R[i]<<" "<<in[i] <<" "<<idx[i] << " "<<Tr[i] <<" "<<Tf[i] <<endl;
//		cerr<<pos[i]<<endl;
	}
	for(int i = n;i <= 2 * n - 2;i ++) {
		int x , y , Val;
		scanf("%d%d%d",&x,&y,&Val);
		back[x] = Val; idback[i] = x;
	}
	Seg.build(1 , 1 , n);
}

int S[N];

#define lowbit(x) (x & (-x))

void Add(int x, int v) {
	for(int i = x;i < N;i += lowbit(i)) S[i] += v;
}

int sum(int x) {
	int res = 0;
	for(int i = x;i;i -= lowbit(i)) res += S[i];
	return res;
}

void do_query(void) {
	for(int i = 1;i <= n;i ++) {
		Add(idx[i] , Tr[i] - Tr[pos[idx[i] - 1]]);
	}
	for(int i = 1;i <= q;i ++) {
		int ty  , x , y;
		scanf("%d%d%d",&ty , &x , & y);
		if(ty == 1) {
			if(x > n - 1) {
				int where = idback[x];
				Seg.chg(1 , idx[where] , idx[where] , y - back[where]); back[where] = y;
			}
			else {
				int where = id_tofa[x];
				Seg.chg(1 , L[where] , R[where] , y - Tf[where]); 
				Add(L[where] , y - Tf[where]); Add(R[where] + 1 , Tf[where] - y); Tf[where] = y;
			}
		}
		else {
			if(is_ancestor(x , y)) {
				printf("%d\n",sum(idx[y]) - sum(idx[x]));
			}
			else {
				printf("%d\n",Seg.query(1 , L[x] ,R[x]) - sum(idx[x]) + sum(idx[y]));
			}
		}
	}
}

int main(void) {
	read();
	do_query();
}