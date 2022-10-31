#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int _abs_int(int a) {
	return a<0 ? -a : a;
}
lli _abs_lli(lli a) {
	return a<0 ? -a : a;
}

int n,m,cl,ce,v;
int ae[100001],al[100001];

int main() {
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=0;i<cl;i++) scanf("%d",al+i);
	for(int i=0;i<ce;i++) scanf("%d",ae+i);
	
	int test;
	scanf("%d",&test);
	while(test--) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);

		if(y1==y2) {
			printf("%d\n",_abs_int(x2-x1));
			continue;
		}

		int mx=1e9;
		int idx=lower_bound(al,al+cl,x1)-al;
		if(idx!=cl) {
			mx = min(mx, _abs_int(x1-al[idx]) + _abs_int(x2-al[idx]) + (y2-y1));
		}
		idx = upper_bound(al,al+cl,x1)-al;
		if(idx!=0) {
			idx--;
			mx = min(mx, _abs_int(x1-al[idx]) + _abs_int(x2-al[idx]) + (y2-y1));
		}
		
		idx = lower_bound(ae,ae+ce,x1)-ae;
		if(idx!=ce) {
			mx = min(mx,_abs_int(x1-ae[idx]) + _abs_int(x2-ae[idx]) + (y2-y1+v-1)/v);
		}
		idx = upper_bound(ae,ae+ce,x1)-ae;
		if(idx!=0) {
			idx--;
			mx = min(mx,_abs_int(x1-ae[idx]) + _abs_int(x2-ae[idx]) + (y2-y1+v-1)/v);
		}
		printf("%d\n",mx);
	}

	return 0;
}