#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, m;
int arr[310][310];
int px[] = {0,1,0,-1};
int py[] = {1,0,-1,0};

int good(int i, int j) {
	return i>=0&&i<n&&j>=0&&j<m;
}

int getv(int i, int j){
	int c = 0;
	for (int d=0;d<4;d++) {
		c += good(i+px[d],j+py[d]);
	}
	return c;
}

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		int mang =0;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				scanf("%d",&arr[i][j]);
				if (arr[i][j]>getv(i,j)) mang = 1;
			}
		}
		if (mang) puts("NO");
		else {
			puts("YES");
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) printf("%d ",getv(i,j));
				puts("");
			}
		}
	}

	return 0;
}