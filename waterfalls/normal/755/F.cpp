#include <bits/stdc++.h>
using namespace std;

int n,k;
int p[1000013];
vector<int> has;

int gethigh() {
	int twos = 0;
	for (int& i: has) twos+=i/2;
	if (k>=twos) return min(n,twos*2+k-twos);
	return min(n,k*2);
}

bitset<1000001> can;
map<int,int> counts;
int getlow() {
	for (int i: has) counts[i]+=1;
	can[0] = 1;
    for (auto p: counts) {
		int x = p.first;
		int y = p.second;
        int on = 1;
        while (on<=y) {
            can|=(can<<(x*on));
            y-=on;
            on*=2;
        }
        can|=(can<<(x*y));
    }
    if (can[k]) return k;
    return k+1;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) {
		if (p[i]) {
			int cur = 0;
			int j = i;
			while (p[j]) {
				cur+=1;
				int k = p[j];
				p[j] = 0;
				j = k;
			}
			has.push_back(cur);
		}
	}
	sort(has.begin(),has.end());
	printf("%d %d\n",getlow(),gethigh());

	return 0;
}