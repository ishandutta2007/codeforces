#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& ci;
typedef const unsigned int& cui;
typedef const long long& cll;
typedef const unsigned long long& cull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%l64d",&x)
#define ul(x) scanf("%l64u",&x)
int gcd(int x, int y) {
	return x == 0 or y == 0? y+x: gcd(y, x%y);
}
	vector<vector<ll> > answers;
int main() {
	int n, m, x, y, a, b;
	i(n);
       	i(m); i(x); i(y); i(a); i(b);
	int l = gcd(a,b);
	a/=l, b/=l;
	long long dx = a * min(m/b, n/a), dy = b*min(m/b, n/a);
//	printf("%Ld %Ld\n", dx, dy);
	assert(dx<=n and dy<=m and dx and dy);
	long long p, q;
	for(int i = -1;i<=2;i++) {
		if(i==-1) p = 0;
		if(i==2) p = n-dx;
		if(i==0 or i==1) p = x - (dx/2)-i;
//		printf("Setting x= %Ld\n", p);
		for(int j = -1; j<=2; j++) {
			if(j==-1) q = 0;
			if(j==2) q = m-dy;
			if(j==0 or j==1) q = y - (dy/2)-j;
//		printf("Setting y= %Ld\n", q);
			if(q<0 or p<0 or p+dx>n or q+dy>m) {
//				printf("Discaring\n");
				continue;
			}
			ll delta = abs(2*x-(2*(ll)p+dx)) + abs(2*y-(2*(ll)q+dy));
//			printf("Delta  %Ld\n", delta);
			vector<ll> X;
			X.resize(5);
			X[0] = delta, X[1] = p, X[2] = q, X[3] = p+dx, X[4] = q+dy;
			answers.push_back(X);
		}
	}
	sort(answers.begin(), answers.end());
	printf("%d %d %d %d", (int)answers[0][1], (int)answers[0][2], (int)answers[0][3], (int)answers[0][4]);
}