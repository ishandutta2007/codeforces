#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<pair<pair<int,int>,int> > edges;
pair<int,int> ans[100013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		edges.push_back(MP(MP(a,1-b),i));
	}
	sort(edges.begin(),edges.end());
	int r = 1;
	int l = 1;
	int lr = 2;
	for (auto e: edges) {
		if (e.A.B==0) {
			r+=1;
			ans[e.B] = MP(1,r);
		} else {
			if (lr>=l) return printf("-1\n"), 0;
			ans[e.B] = MP(l,lr);
			lr+=1;
		}
		while (lr>=l && r>l) {
			l+=1;
			lr = 2;
		}
	}
	for (int i=0;i<m;i++) printf("%d %d\n",ans[i].A,ans[i].B);

	return 0;
}