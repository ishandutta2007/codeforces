#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[1000013], b[1000013];
vector<int> comp;
int has[6000013];
vector<pair<int,int> > ans;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		a[i]*=2;
		b[i]*=2;
		for (int j=-1;j<=1;j++) comp.push_back(a[i]+j);
		for (int j=-1;j<=1;j++) comp.push_back(b[i]+j);
	}
	comp.push_back(-2.1e9);
	comp.push_back(2.1e9);
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (int i=0;i<n;i++) {
		has[lower_bound(comp.begin(),comp.end(),a[i])-comp.begin()]+=1;
		has[upper_bound(comp.begin(),comp.end(),b[i])-comp.begin()]-=1;
	}
	for (int i=1;i<comp.size();i++) has[i]+=has[i-1];
	int i = 0;
	while (true) {
		while (has[i]<k && i<comp.size()) i+=1;
		if (i==comp.size()) break;
		int from = comp[i]/2;
		while (has[i]>=k) i+=1;
		int to = (comp[i]-1)/2;
		ans.push_back(make_pair(from,to));
	}
	printf("%d\n",ans.size());
	for (auto p: ans) printf("%d %d\n",p.first,p.second);

	return 0;
}