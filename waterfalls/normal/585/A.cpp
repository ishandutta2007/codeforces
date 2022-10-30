#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int v[4013], d[4013];
ll p[4013];
set<int> line;
vector<int> ans;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&v[i],&d[i],&p[i]);
		line.insert(i);
	}
	while (line.size()>0) {
		int x = *line.begin();
		line.erase(line.begin());
		ans.push_back(x);
		int has = v[x];
		for (int i: line) {
			p[i]-=has;
			has-=1;
			if (has==0) break;
		}
		for (int i: line) {
			if (p[i]<0) for (int j: line) if (j>i) p[j]-=d[i];
		}
		for (int i=0;i<n;i++) if (p[i]<0 && line.count(i)) line.erase(i);
	}
	printf("%d\n",ans.size());
	for (int i: ans) printf("%d ",i+1);
	printf("\n");

	return 0;
}