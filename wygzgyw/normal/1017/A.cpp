#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> d[1010];
bool cmp(pair<int,int> x,pair<int,int> y) {
	if (x.first==y.first) return x.second<y.second;
	return x.first>y.first;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int x,y,z,w;
		scanf("%d %d %d %d",&x,&y,&z,&w);
		d[i]=make_pair(x+y+z+w,i);
	}
	sort(d+1,d+(n+1),cmp);
	for (int i=1;i<=n;i++)
		if (d[i].second==1) {
			printf("%d\n",i); break;
		}
	return 0;
}