#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;
typedef long long lli;

int a[4];
int n=4;
int main() {
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=201;i>=0;i--) {
		for(int j=i-1;j>=1;j--) {
			for(int k=j-1;k>=1;k--) {
				if( a[0]<=i && 2*a[0]>=i &&
					a[1]<=j && 2*a[1]>=j && 2*a[1]<i &&
					a[2]<=k && 2*a[2]>=k && 2*a[2]<i && 2*a[2]<j &&
					a[3]<=k && 2*a[3]>=k && 2*a[3]<i && 2*a[3]<j) {
					printf("%d\n%d\n%d\n",i,j,k);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}