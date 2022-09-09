#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
int S[110][110];

int inp() {
	int c;
	scanf("%d",&c);
	return c-1;
}
void oup(int c, int x, int y) {
	printf("%d %d %d\n",c+1,x+1,y+1);
	S[x][y] = c;
	fflush(stdout);
}

int main() {
	scanf("%d",&N);
	int a0 = -1, a1 = -1;
	int c0 = 0, c1 = 0;
	int m0=(N*N+1)/2, m1=(N*N)/2;
	vector<pii> v0, v1;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			if ((i+j)%2==0) v0.push_back({i,j});
			else v1.push_back({i,j});
		}
	}

	for (int i=0;i<N*N;i++) {
		int a = inp();
		if (i==0) {
			int b = (a+1)%3;
			oup(b,0,0);
			a0 = b;
			c0++;
			continue;
		}
		else if (i==1) {
			int b = 0;
			for (;b<3;b++) if (b!=a&&b!=a0) break;
			oup(b,0,1);
			a1 = b;
			c1++;
			continue;
		}
		else if (c0<m0&&c1<m1){
			if (a==a0) {
				oup(a1,v1[c1].first,v1[c1].second);
				c1++;
			}
			else {
				oup(a0,v0[c0].first,v0[c0].second);
				c0++;
			}
		}
		else {
			if (c0==m0) {
				int b = 0;
				for (;b<3;b++) if (b!=a&&b!=a0) break;
				oup(b,v1[c1].first,v1[c1].second);
				c1++;
			}
			else {
				int b = 0;
				for (;b<3;b++) if (b!=a&&b!=a1) break;
				oup(b,v0[c0].first,v0[c0].second);
				c0++;
			}
		}
	}

	return 0;
}