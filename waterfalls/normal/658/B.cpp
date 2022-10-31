#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,k,q;
int t[150013];
bool on[150013];
priority_queue<pair<int,int> > has;

int main() {
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	for (int i=0;i<q;i++) {
		int type,id;
		scanf("%d%d",&type,&id);
		if (type==1) {
			has.push(MP(-t[id],id));
			on[id] = 1;
			if (has.size()>k) {
				on[has.top().B] = 0;
				has.pop();
			}
		} else {
			printf("%s\n",on[id] ? "YES" : "NO");
		}
	}

	return 0;
}