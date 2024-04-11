#include <bits/stdc++.h>
using namespace std;

int n,q;
int status[300013];
queue<int> has[300013];
queue<int> all;

int main() {
	scanf("%d%d",&n,&q);
	int ans = 0;
	int last = 0;
	while (q--) {
		int type, x;
		scanf("%d%d",&type,&x);
		if (type==1) {
			has[x].push(q);
			all.push(q);
			ans+=1;
		} else if (type==2) {
			while (has[x].size()>0) {
				ans-=!status[has[x].front()];
				status[has[x].front()] = 1;
				has[x].pop();
			}
		} else {
			for (int i=0;i<x-last;i++) {
				ans-=!status[all.front()];
				status[all.front()] = 1;
				all.pop();
			}
			last = max(last,x);
		}
		printf("%d\n",ans);
	}

	return 0;
}