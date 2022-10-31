#include <bits/stdc++.h>
using namespace std;

const string good = "2017";
const string bad = "2016";

struct Data {
	int cost[5][5];
	Data() {
		for (int i=0;i<5;i++) {
			for (int j=0;j<5;j++) {
				cost[i][j] = 1e9;
			}
		}
		for (int i=0;i<5;i++) cost[i][i] = 0;
	}
	Data operator+(Data o) {
		Data res;
		for (int i=0;i<5;i++) res.cost[i][i] = 1e9;
        for (int i=0;i<5;i++) {
			for (int j=i;j<5;j++) {
                for (int k=j;k<5;k++) {
					res.cost[i][k] = min(res.cost[i][k],cost[i][j]+o.cost[j][k]);
                }
			}
        }
        return res;
	}
};

char s[200013];

class ST {
private:
	int size;
	Data st[1<<19];

	void build(int w, int L, int R) {
		if (L==R) {
			if (s[L]==bad[3]) {
				st[w].cost[3][3] = 1;
				st[w].cost[4][4] = 1;
			}
			for (int i=0;i<4;i++) {
				if (s[L]==good[i]) {
					st[w].cost[i][i+1] = 0;
					st[w].cost[i][i] = 1;
				}
			}
		} else {
			build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
			st[w] = st[w*2]+st[w*2+1];
		}
	}
	Data query(int w, int L, int R, int a, int b) {
		if (b<L || R<a) return Data();
		if (a<=L && R<=b) return st[w];
		return query(w*2,L,(L+R)/2,a,b)+query(w*2+1,(L+R)/2+1,R,a,b);
	}
public:
	void build(int n) {
		size = n;
		build(1,1,size);
	}
	Data query(int a, int b) { return query(1,1,size,a,b); }
};

int n,q;
ST tree;

int main() {
	scanf("%d%d",&n,&q);
	scanf(" %s",s+1);
	tree.build(n);
	while (q--) {
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = tree.query(a,b).cost[0][4];
		if (ans<=n) printf("%d\n",ans);
		else printf("-1\n");
	}

	return 0;
}