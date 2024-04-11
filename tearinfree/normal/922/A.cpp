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

const lli mod=1e9+7;

int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==0) {
		puts("No");
		return 0;
	}
	b--;
	if(b==0 && a!=0) {
		puts("No");
		return 0;
	}
	if( a-b>=0 && (a-b)%2==0) puts("Yes");
	else puts("No");

	return 0;
}