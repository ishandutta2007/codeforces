#include <bits/stdc++.h>
using namespace std;

const int dX[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dY[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n;
bool has[30][313][313][6][8];

void go(int i) {
    for (int t=5;t>0;t--) {
		for (int x=0;x<313;x++) {
			for (int y=0;y<313;y++) {
				for (int d=0;d<8;d++) {
					if (has[i][x][y][t][d]) {
                        has[i][x+dX[d]][y+dY[d]][t-1][d] = 1;
					}
				}
			}
		}
    }
}

int main() {
	scanf("%d",&n);
	int t;
	scanf("%d",&t);
	t-=1;
	has[0][150][150][t][0] = 1;
	go(0);
	for (int i=1;i<n;i++) {
		scanf("%d",&t);
		for (int x=0;x<313;x++) {
			for (int y=0;y<313;y++) {
				for (int d=0;d<8;d++) {
					if (has[i-1][x][y][0][d]) {
						has[i][x][y][t][(d+1)%8] = 1;
						has[i][x][y][t][(d+7)%8] = 1;
					}
				}
			}
		}
		go(i);
	}
	int ans = 0;
	for (int x=0;x<313;x++) {
		for (int y=0;y<313;y++) {
			bool cur = 0;
			for (int i=0;i<n;i++) {
				for (int t=0;t<6;t++) {
					for (int d=0;d<8;d++) {
						cur|=has[i][x][y][t][d];
					}
				}
			}
			ans+=cur;
		}
	}
	printf("%d\n",ans);

	return 0;
}