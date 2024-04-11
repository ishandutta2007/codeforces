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

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int main() {
	lli x,d;
	scanf("%lld%lld",&x,&d);

	vector<lli> ans;
	lli t=1,v=-1;
	while(x) {
		if(x&1) {
			if(v==-1) ans.push_back(t);
			else {
				for(int k=0;k<=v;k++) ans.push_back(t);
				t+=d+1;
				ans.push_back(t);
			}
		}
		t+=d+1;
		x>>=1;
		v++;
	}
	printf("%d\n",ans.size());
	for(auto &it:ans) printf("%lld ",it);
	
	return 0;
}