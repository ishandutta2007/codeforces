#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e6+5;
mt19937 rng(time(0));

int n, top;
LL a[N], s[N];
struct point{
	LL x, y;
	point operator-(point r){return {x-r.x, y-r.y};}
}st[N];

bool cmp(point a, point b, point c){
	point d1 = b-a, d2 = c-b;
	return d1.x*d2.y-d2.x*d1.y>=0;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	s[0] = 0;
	rep(i,1,n) s[i] = s[i-1] + a[i];
	
	st[1] = {0, 0};
	st[2] = {1, s[1]};
	top = 2;
	rep(i,2,n){
		while(!cmp(st[top-1], st[top], {i,s[i]})) --top;
		st[++top] = {i, s[i]};
	}
	
	rep(i,2,top){
		int num = st[i].x - st[i-1].x;
		double avg = 1.0 * (st[i].y-st[i-1].y) / num;
		rep(j,1,num) printf("%.10lf\n", avg);
	}
	return 0;
}