%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 3e5 + 5;
const int Segment_Size = N * 4;

#define lc no<<1
#define rc no<<1|1
#define getmid int mid = (L[no] + R[no]) >> 1;

int L[Segment_Size] , R[Segment_Size] , n , m;
long long a[N];

struct NODE{
	int Ld,Rd,Lu,Ru,mx,S,l,r,Lp,Rp;
	void init(int x) {
		Ld = Rd = Lu = Ru = mx = 0;
		if(x == -1) return;
		S = 1;
		mx = 1;
		Lp = Rp = 1;
		if(a[x] < 0) {
			Ld = 1;
		}
		
		if(a[x] > 0) {
			Lu = 1;
		}
		
		if(a[x + 1] > 0) {
			Ru = 1;
		}
		
		if(a[x+1] < 0) {
			Rd = 1;
		}
		
		return;
	}
	void print() {
		cout<<"Ld: "<<Ld<<" Rd: "<<Rd<<" Lu: "<<Lu<<" Ru: "<<Ru<<" mx: "<<mx<<" S: "<<S<<" l: "<<l<<" r: "<<r<<" Lp: "<<Lp<<" Rp: "<<Rp<<endl;
	}
};

NODE info[Segment_Size] , ans;

NODE operator + (NODE le, NODE ri) {
	NODE res;
	res.init(-1);
	res.S = le.S + ri.S;
	res.l = le.l;
	res.r = ri.r;
	if(le.Rd == le.S && a[le.r + 1] < 0) {
		res.Ld = le.S + ri.Ld;
	}
	else res.Ld = le.Ld;
	
	if(le.Ru == le.S && a[le.r + 1] > 0) {
		res.Lu = le.S + ri.Lu;
	}
	else res.Lu = le.Lu;
	
	if(ri.Lu == ri.S&& a[le.r + 1] > 0) {
		res.Ru = ri.S + le.Ru ;
	}
	else res.Ru = ri.Ru;
	
	if(ri.Ld == ri.S&& a[le.r + 1] < 0) {
		res.Rd = ri.S + le.Rd ;
	}
	else res.Rd = ri.Rd;
	
	res.Lp = le.Lp;
	res.Rp = ri.Rp;
	res.Lp = max(res.Lp , le.Lu);
	res.Rp = max(res.Rp , ri.Rd);
	res.mx = max(res.mx , le.mx);
	res.mx = max(res.mx , ri.mx);
	if(a[le.r + 1] != 0) res.mx = max(res.mx , le.Ru + ri.Ld);
	
	if(a[le.r + 1] < 0) {
		if(le.Lp == le.S) {
			res.Lp = max(res.Lp , le.Lp + ri.Ld);
		}
		if(ri.Ld == ri.S) {
			res.Rp = max(res.Rp , ri.Ld + le.Rp);
		}
		res.mx = max(res.mx , le.Rp + ri.Ld);
	}
	
	if(a[le.r + 1] >0) {
		if(le.Lu == le.S) {
			res.Lp = max(res.Lp , le.Lu + ri.Lp);
		}
		if(ri.Lp == ri.S) {
			res.Rp = max(res.Rp , ri.Lp + le.Ru);
		}
		res.mx = max(res.mx , ri.Lp + le.Ru);
	}
	
	res.mx = max(res.mx , res.Rp);
	res.mx = max(res.mx , res.Lp); 
	return res;
}

void build(int no,int l,int r) {
	L[no] = l; R[no] = r;
	if(l == r) {
		info[no].init(l);
		info[no].l = l;
		info[no].r = r;
		return;
	}
	getmid;
	build(lc,l,mid);build(rc,mid+1,r);
	info[no] = info[lc] + info[rc];
}

void add(int no ,int x,int v) {
	if(L[no] == R[no]) {
		a[x] += v;
		info[no].init(x);
//		cout<<no<<" "<<"QAQ"<<endl;
//		info[no].print();
//		cout<<x<<" "<<a[x]<<" "<<"QAQ"<<" "<<x+1<<" "<<a[x+1]<<endl;
		return;
	}
	getmid;
	if(x > mid) add(rc , x, v);
	else if(x <= mid) add(lc,x,v);
	info[no] = info[lc] + info[rc];
//	cout<<no<<" "<<"QAQ"<<endl;
//	info[no].print();
}

void query(int no,int l,int r) {
	if (L[no] == l &&R[no] == r) {
		if(!ans.S)ans = info[no];
		else ans = ans + info[no];
		return;
	}
	getmid;
	if(l > mid) {
		query(rc , l , r);
	}
	else if (mid <= r) query(lc , l, r);
	else {
		query(lc,l,mid); query(rc,mid + 1, r);
	}
}

main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
	for(int i = n;i >= 1;i --) {
		a[i] = a[i] - a[i - 1];
	}
	build(1 , 1 , n);
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++) {
		int l , r , k;
		scanf("%d%d%d",&l,&r,&k);
		if(r != n) add(1 , r + 1, -k);
		add(1,r,0);
		add(1 , l , k);
		if(l != 1) add(1,l-1,0);
		ans.init(-1);
		ans.S = 0;
		query(1,1,n);
		printf("%d\n" , ans.mx);
	}
}