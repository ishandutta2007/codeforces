#include <bits/stdc++.h>
using namespace std;

int n,m;
int where[100013];
int cnt[100013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int f;
		scanf("%d",&f);
		where[f] = i;
		cnt[f]+=1;
	}
	int ok = 1;
	vector<int> ans;
	for (int i=1;i<=m;i++) {
		int b;
		scanf("%d",&b);
		if (cnt[b]>1) ok = 2;
		if (cnt[b]==0) {
			ok = 0;
			break;
		}
		ans.push_back(where[b]);
	}
	if (ok==0) printf("Impossible\n");
	else if (ok==2) printf("Ambiguity\n");
	else {
		printf("Possible\n");
		for (int i: ans) printf("%d ",i);
		printf("\n");
	}

	return 0;
}