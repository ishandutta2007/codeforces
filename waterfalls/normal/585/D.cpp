#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
int l[25],m[25],w[25];
map<pair<int,int>,pair<int,int> > one,two;

inline void make(int cur, int bound, int a, int b, int c, int res, map<pair<int,int>,pair<int,int> >& has) {
	if (cur==bound) {
		auto here = MP(b-a,c-b);
		if (!has.count(here)) has[here] = MP(a,res);
		else has[here] = max(has[here],MP(a,res));
	} else {
		make(cur+1,bound,a+l[cur],b+m[cur],c,res*3+2,has);
		make(cur+1,bound,a+l[cur],b,c+w[cur],res*3+1,has);
		make(cur+1,bound,a,b+m[cur],c+w[cur],res*3+0,has);
	}
}

stack<int> has;
char rev[3] = {'L','M','W'};
void output(int cur, int num) {
	for (int i=0;i<num;i++) {
		has.push(cur%3);
		cur/=3;
	}
	while (has.size()>0) {
		for (int d=0;d<3;d++) if (has.top()!=d) printf("%c",rev[d]);
		printf("\n");
		has.pop();
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d%d",&l[i],&m[i],&w[i]);
	make(0,n/2,0,0,0,0,one);
	make(n/2,n,0,0,0,0,two);
	int high = -2147483647;
	pair<int,int> which;
	for (auto x: one) {
		auto y = MP(-x.A.A,-x.A.B);
		if (two.count(y)) {
			int cur = x.B.A+two[y].A;
			if (cur>high) high = cur, which = x.A;
		}
	}
	if (high==-2147483647) return printf("Impossible\n"), 0;
	auto x = MP(which,one[which]);
	auto y = MP(-x.A.A,-x.A.B);
	auto ans = two[y].B;
	output(one[x.A].B,n/2);
	output(two[y].B,n-n/2);

	return 0;
}