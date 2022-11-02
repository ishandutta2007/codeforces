#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e5 + 5;
const int steps = 100;
const ldb eps = 1e-9;

struct item{
	int m, v, id;
};

bool operator < (const item & l, const item & r){
	ret (l.m < r.m) || (l.m == r.m && l.v < r.v);
}

int k, n, h;
item a[MAXN];
int p[MAXN];

bool can(ldb x){
	int ptr = k - 1;
	DF(i, n - 1, -1){
		if(ptr == -1)brk;
		int clen = (ptr + 1) * h;
		if(clen - eps < x * a[i].v){p[ptr--] = i;}
	}
//	printf("%.15lf %d\n", (double)x, ptr);
	ret ptr == -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &k, &h);
	F(i, 0, n)a[i].id = i;
	F(i, 0, n)scanf("%d", &a[i].m);
	F(i, 0, n)scanf("%d", &a[i].v);
	sort(a, a + n);
	ldb l = 0, r = 1e9 + 9;
	F(i, 0, steps){
		ldb mid = (l + r)/2;
		if(can(mid))r = mid;
		else l = mid;
	}
	ldb ans = (l + r)/2;
	assert(can(r));
//	printf("%.15lf %.15lf\n", (double)l, (double)r);
	F(i, 0, k)printf("%d ", a[p[i]].id + 1);
	return 0;
}