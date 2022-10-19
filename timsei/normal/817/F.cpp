#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include<cassert>
using namespace std;

#define int long long

const int N = 400005;
const int Segment_Size = N * 4;
const int INF =1e18 + 1;

map<int,int>M , C;

#define lc no << 1
#define rc no << 1 | 1
#define getmid int mid = (L[no] + R[no]) >> 1;

// build shao bing

int Max;

namespace Tr {
	int L[Segment_Size] , R[Segment_Size] , rev[Segment_Size] , in[Segment_Size] , mex[Segment_Size] , Mex[Segment_Size] , all[Segment_Size];
	void build(int no , int l ,int r) {
		L[no] = l; R[no] = r; 
		if(l == r) {
			rev[no] = in[no] = mex[no] = all[no] = 0;
			mex[no] = l; Mex[no] = 1e18 + 1;
			return;
		}
		rev[no] = in[no] = mex[no] = all[no] = 0;
		mex[no] = l; Mex[no] = 1e18 + 1;		
		getmid;
		build(lc , l , mid); build(rc , mid + 1, r);
	}
	
	void pushup(int no) {
		if(L[no] == R[no]) return;
		mex[no] = min(mex[lc] , mex[rc]);
		Mex[no] = min(Mex[lc] , Mex[rc]);
	}
	
	void pushdown(int no) {
		if(rev[no] && all[no]) assert(0);
		if(L[no] == R[no]) all[no] = rev[no] = 0;
		if(L[no] == R[no]) return;
		if(all[no]) {
			if(rev[lc]) rev[lc] = 0; if(rev[rc]) rev[rc] = 0;
			if(all[no] == 1) {
				mex[lc] = 1e18 + 1; Mex[lc] = L[lc];
				mex[rc] = 1e18 + 1; Mex[rc] = L[rc];
				all[lc] = all[rc] = 1;
			}
			else {
				mex[lc] = L[lc]; Mex[lc] = 1e18 + 1;
				mex[rc] = L[rc]; Mex[rc] = 1e18 + 1;
				all[lc] = all[rc] = 2;
			}
			all[no] = 0;
		}
		
		if(rev[no]) {
			if(all[lc]) pushdown(lc); if(all[rc]) pushdown(rc);
			rev[lc] ^= 1; rev[rc] ^= 1; 
			swap(mex[lc] , Mex[lc]);
			swap(mex[rc] , Mex[rc]); 
			rev[no] = 0;
		}
		pushup(no);
	}
	
	void invert(int no , int l , int r) {
		if(L[no] == l && R[no] == r) {
			if(all[no]) pushdown(no);
			swap(mex[no] , Mex[no]); rev[no] ^= 1; 
			return;
		}
		pushdown(no);
		getmid;
		if(l > mid) invert(rc , l , r);
		else if(r <= mid) invert(lc , l , r);
		else invert(lc , l , mid) , invert(rc , mid + 1 , r);
		pushup(no);
	}
	
	void all_dance(int no , int l , int r , int aim) {
		if(L[no] == l && R[no] == r) {
			if(rev[no]) rev[no] = 0;
			all[no] = aim; 
			if(aim == 1) {
				mex[no] = 1e18 + 1; Mex[no] = l;
			}
			else Mex[no] = 1e18 + 1 , mex[no] = l;
			return;
		}
		pushdown(no);
		getmid;
		if(r <= mid) all_dance(lc , l , r , aim);
		else if(l > mid) all_dance(rc , l , r , aim);
		else all_dance(lc , l , mid , aim) , all_dance(rc , mid + 1 , r , aim);
		pushup(no);
	}
	
	int query(void) {
		pushdown(1);
		return mex[1];
	}
}

using namespace Tr;

int n , l , r , ty[N] , x[N] , y[N] , cnt , id[N];

main(void) {
	cin>>n;
	for(int i = 1;i <= n;i ++) {
		cin>>ty[i]>>x[i]>>y[i];
		M[x[i]] ++; M[y[i]] ++; M[x[i] + 1] ++; M[y[i] + 1] ++;
	}
	M[1] ++;
	for(map<int,int>::iterator it = M.begin(); it != M.end();it ++) {
		id[++ cnt] = it ->first; C[it -> first] = cnt;
	}
	
	Tr::build(1 , 1 , cnt);
	
	for(int i = 1;i <= n;i ++) {
		x[i] = C[x[i]]; y[i] = C[y[i]];
		if(ty[i] == 3) Tr::invert(1 , x[i] , y[i]);
		else Tr::all_dance(1 , x[i] , y[i] , ty[i]);
		int ans = Tr::query();
//		cerr<<ans <<" aa"<<endl;
		if(ans > 1e15) {
			printf("%lld\n" , id[cnt] + 1);
		}
		else printf("%lld\n" , id[ans]);
	}	
}