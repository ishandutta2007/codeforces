#include <bits/stdc++.h>

using namespace std;

int n,k,can,cur;
vector<int> need;

int main() {
	scanf("%d%d",&n,&k);
	can = 0;
	cur = 0;
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		if (a%10) need.push_back(10-a%10);
		cur+=a/10;
		if (a%10) a+=10-a%10;
		can+=(100-a)/10;
	}
	sort(need.begin(),need.end());
	for (int i: need) {
		if (i>k) break;
		k-=i;
		cur+=1;
	}
	cur+=min(k/10,can);
	printf("%d\n",cur);

	return 0;
}