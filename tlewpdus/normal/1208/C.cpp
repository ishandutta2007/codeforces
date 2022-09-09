#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int ans[1010][1010];

int main() {
	scanf("%d",&n);

	int p = 0;
	for (int i=0;i<n/4;i++) {
		for (int j=0;j<n/4;j++) {
			for (int k=0;k<4;k++) {
				for (int l=0;l<4;l++) {
					ans[i*4+k][j*4+l]=p++;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}

	return 0;
}