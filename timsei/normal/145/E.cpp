#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;
const int Segment_Size = N * 4;

int S[Segment_Size][2] , go[Segment_Size][2] , rev[Segment_Size] , L[Segment_Size] , R[Segment_Size] , n , m , l , r , i;
char org[N];

#define lc no << 1
#define rc no << 1 | 1
#define getmid int mid = (L[no] + R[no]) >> 1

void up(int no) {
	for(i = 0;i < 2;++ i) S[no][i] = S[lc][i] + S[rc][i];
	go[no][0] = max(S[lc][0] + go[rc][0] , go[lc][0] + S[rc][1]);
	go[no][1] = max(S[lc][1] + go[rc][1] , go[lc][1] + S[rc][0]);
}

void build(int no , int l , int r) {
	L[no] = l; R[no] = r;
	if(l == r) {
		if(org[l] == '4') org[l] = 0; else org[l] = 1;
		S[no][org[l]] = go[no][0] = go[no][1] = 1; return;
	}
	getmid; 
	build(lc , l , mid); build(rc , mid + 1 , r);
	up(no);
}

void rever(int no) {
	rev[no] ^= 1;
	swap(S[no][0] , S[no][1]); swap(go[no][0] , go[no][1]);
}

void dn(int no) {
	if(L[no] == R[no] || !rev[no]) return;
	rever(lc); rever(rc); rev[no] = 0;
}

void swi(int no , int l , int r) {
	if(L[no] == l && R[no] == r) {
		rever(no); return;
	}
	dn(no);
	getmid;
	if(l > mid) swi(rc , l , r); else if(r <= mid) swi(lc , l , r); else swi(lc , l , mid) , swi(rc , mid + 1 , r);
	up(no);
}

int main(void) {
	scanf("%d%d" , &n , &m);
	scanf("%s" , org + 1);
	build(1 , 1 , n);
	for(;m --;) {
		scanf("%s" , org);
		if(org[0] == 's') scanf("%d%d", &l , &r) , swi(1 , l , r);
		else printf("%d\n" , go[1][0]);
	}
}