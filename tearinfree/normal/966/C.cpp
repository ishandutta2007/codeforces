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

int n;
lli arr[300000],res[300000];
vector<lli> val[61];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);
	
	lli bx=0;
	for(int i=0;i<n;i++) {
		int mx=0;
		for(int j=0;j<60;j++) if(arr[i] >> j & 1) mx=j;
		val[mx].push_back(arr[i]);
		bx^=arr[i];
	}
	for(int i=n-1;i>=0;i--) {
		int f=0;
		for(int j=0;j<60;j++) if( (bx >> j & 1) && (!val[j].empty())) {
			res[i] = val[j].back();
			bx ^= val[j].back();
			val[j].pop_back();
			f=1;
			break;
		}
		if(!f) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=0;i<n;i++) {
		printf("%lld ",res[i]);
	}
	
	return 0;
}