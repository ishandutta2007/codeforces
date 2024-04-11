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

int n,arr[200001];
char str[200002];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	scanf("%s",str+1);
	
	int mx=0;
	for(int i=1;i<=n;i++) {
		mx=max(mx,arr[i]);
		if(str[i]=='0') {
			if(mx>i) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	
	return 0;
}