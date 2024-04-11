#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iostream>
#include <set>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

lli len[70], st[70], sh[70];

int main() {
	int n;
	scanf("%d",&n);
	
	len[0] = 1;
	for(int i=1;i<70;i++) len[i] = len[i-1] * 2;
	
	while(n--) {
		int t;
		scanf("%d",&t);
		if(t!=3) {
			lli a,b;
			scanf("%lld%lld",&a,&b);
			
			int idx=0;
			while(a>=2) {
				idx++; a/=2;
			}
			
			b %= len[idx];
			if(b<0) b+=len[idx];

			if(t==1) {
				sh[idx] = (sh[idx] + b) % len[idx];
			}
			else {
				st[idx] = (st[idx] + b) % len[idx];
			}
		}
		else {
			lli cur;
			scanf("%lld",&cur);
			
			lli v=cur;
			int idx=0;
			while(v>1) {
				v/=2; idx++;
			}
			while(cur>1) {
				printf("%lld ",cur);
				
				lli cp = ((cur-len[idx]) + st[idx] + sh[idx] + st[idx-1] * 2)%len[idx];

				cp += len[idx];
				cp /= 2;


				lli tp = cp - len[idx-1];
				tp = (tp + (len[idx-1] - st[idx-1]) + (len[idx-1] - sh[idx-1])) % len[idx-1];
				tp += len[idx-1];
				
				cur = tp;
				idx--;
			}
			printf("%d\n",1);
		}
	}
	
	return 0;
}