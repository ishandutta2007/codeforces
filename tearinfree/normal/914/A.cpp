#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,arr[1000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	int mx=-1e7;
	for(int i=0;i<n;i++) {
		int f=0;
		for(int j=0;j<=1000;j++) {
			if(j*j==arr[i]) {
				f=1;
				break;
			}
		}
		if(!f) mx=max(mx,arr[i]);
	}
	printf("%d\n",mx);
	
	return 0;
}