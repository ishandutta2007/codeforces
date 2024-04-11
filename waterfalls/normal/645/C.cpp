#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[100013];

deque<int> has;

int main() {
	scanf("%d%d %s",&n,&k,&s);
	k+=1;
	int r = -1;
	int ans = 1e9;
	for (int l=0;l<n;l++) {
		while (has.size()<k && r<n) {
			r+=1;
			if (s[r]=='0') has.push_back(r);
		}
		if (has.size()<k) break;
		int mid = upper_bound(has.begin(),has.end(),(l+r)/2)-has.begin();
		ans = min(ans,max(r-has[mid],has[mid]-l));
		if (mid) {
			mid-=1;
			ans = min(ans,max(r-has[mid],has[mid]-l));
		}
		if (has.front()==l) has.pop_front();
	}
	printf("%d\n",ans);

    return 0;
}