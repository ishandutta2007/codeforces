#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

// More templates here

#define MAXN (300004)

int A[MAXN];
int N, Q;

struct N60 {int n[60];} n0;

class SegmentTree1
{
public:
// (*)
	typedef N60 value_t; typedef int qvalue_t; typedef int qresult_t;

	int ready;
	VI l_b, r_b; // left/right bound (interval)
	int q_l, q_r; // query left/right (interval)
	int size, base; // ~2*|array|, ~|array|, both must be power of 2
	vector <value_t> seg_value;
	qvalue_t query_value; qresult_t query_result;

//(*)
	inline value_t   def_value()   {return n0;}
	inline qresult_t def_qresult() {return 0;}
	inline void accum_result(int id)
	{
		query_result += seg_value[id].n[query_result%60];
	}
	inline void update_value(int id)
	{
		FOR(i,0,60) seg_value[id].n[i] = 1 + (i % A[query_value] == 0);
	}
	inline void update_parent_value(int id, int lc, int rc)
	{
		FOR(i,0,60)
		{
			int a = seg_value[lc].n[i];
			seg_value[id].n[i] = a + seg_value[rc].n[(a+i)%60];
		}
	}
	inline void build_parent_value(int id, int lc, int rc)
	{
		update_parent_value(id,lc,rc);
	}

	inline int l_ch(int id) {return id+id;}
	inline int r_ch(int id) {return id+id+1;}
	void seg_merge(int id) {
		int lc = l_ch(id), rc = r_ch(id);
		if(!ready) build_parent_value(id,lc,rc);
		else update_parent_value(id,lc,rc);
	} void internal_query(int id) {
		if(q_r < l_b[id] || r_b[id] < q_l) return;
		if(q_l <= l_b[id] && r_b[id] <= q_r) {accum_result(id); return;}
		internal_query(l_ch(id)); internal_query(r_ch(id));
	} void update_bound(int id, int l, int r) {
		l_b[id] = l; r_b[id] = r; if(l >= r) return;
		int m = (l+r) / 2; update_bound(l_ch(id), l, m); update_bound(r_ch(id), m+1, r);
	}

public:
	SegmentTree1() {init(vector <value_t> ());}
	SegmentTree1(int n) {init(vector <value_t> (n, def_value()));}
	SegmentTree1(const vector <value_t> A) {init(A);}
	void init(const vector <value_t> &A) {
		ready = 0;
		int n = A.size(); if(n <= 0) {base = size = 0; return;}
		base = 2; while(base < n) base <<= 1; size = base * 2;
		// base >= 2, size >= 4, to avoid too small cases
		l_b.resize(size); r_b.resize(size); seg_value.resize(size, def_value());
		update_bound(1, 0, base-1);
		FOR(i,0,n) seg_value[i + base] = A[i]; ROF(i,base-1,0) seg_merge(i);
		ready = 1;
	}
	void update(int p, const qvalue_t value) {
		int id = p + base; query_value = value; update_value(id);
		while((id=id/2) >= 1) seg_merge(id);
	}
	qresult_t query(int l, int r) {
		query_result = def_qresult(); q_l = l; q_r = r;
		internal_query(1); return query_result;
	}
	int leaves_count() const {return size - base;}
};

int main()
{
	cin >> N;
	FOR(i,0,N) scanf("%d", A+i);

	SegmentTree1 T(N);
	FOR(i,0,N) T.update(i, i);

	cin >> Q;
	FOR(i,0,Q)
	{
		char s[4];
		int a, b;
		scanf("%s %d %d", s, &a, &b);
		if(s[0] == 'A')
		{
			int res = T.query(a-1, b-2);
			printf("%d\n", res);
		}
		else
		{
			A[a-1] = b;
			T.update(a-1, a-1);
		}
	}

	return 0;
}