#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int _abs(int a) {
	return a<0 ? -a : a;
}
int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
	int n,k,val,arr[201];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) arr[i]=301;
	for(int i=0;i<k;i++) {
		scanf("%d",&val);
		for(int p=1;p<=n;p++) arr[p]=min(arr[p],_abs(val-p));
	}
	
	printf("%d\n",*max_element(arr+1,arr+n+1)+1);
	}
	
	return 0;
}