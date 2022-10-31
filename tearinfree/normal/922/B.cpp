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
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			int k=i^j;
			if(k<=n && k>=j && i+j>k) {
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}