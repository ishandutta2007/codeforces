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

int n,arr[100000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	sort(arr,arr+n);

	int i=n-1;
	for(;i>=0;) {
		int j=i;
		for(;j>=0 && arr[i]==arr[j];j--);
		
		if( (i-j)%2 ) break;
		i=j;
	}
	puts(i==-1 ? "Agasa" : "Conan");

	return 0;
}