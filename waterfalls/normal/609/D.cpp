#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m,k,s;
int d[200013], p[200013];
vector<pair<ll,int> > one,two;

bool check(int high) {
	for (int i=0;i<=k;i++) {
		if (one.size()<=i || two.size()<=k-i) continue;
		if (one[i].A*d[high]+two[k-i].A*p[high]<=s) return true;
	}
	return false;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&k,&s);
	d[0] = p[0] = 1e9;
	for (int i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		if (i) d[i] = min(d[i],d[i-1]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
		p[i] = min(p[i],p[i-1]);
	}
	one.resize(1); two.resize(1);
	for (int i=1;i<=m;i++) {
		int type,c;
		scanf("%d%d",&type,&c);
		if (type==1) one.push_back(MP(c,i));
		else two.push_back(MP(c,i));
	}
	sort(one.begin(),one.end());
	sort(two.begin(),two.end());
	for (int i=1;i<one.size();i++) one[i].A+=one[i-1].A;
	for (int i=1;i<two.size();i++) two[i].A+=two[i-1].A;
	int low = 0;
	int high = n+1;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	printf("%d\n",(high<=n) ? high : -1);
	if (high>n) return 0;
	for (int i=0;i<=k;i++) {
		if (one.size()<=i || two.size()<=k-i) continue;
		if (one[i].A*d[high]+two[k-i].A*p[high]<=s) {
			int loc = 0;
			for (int j=1;j<=high;j++) if (d[j]<d[j-1]) loc = j;
			for (int j=1;j<=i;j++) printf("%d %d\n",one[j].B,loc);
			for (int j=1;j<=high;j++) if (p[j]<p[j-1]) loc = j;
			for (int j=1;j<=k-i;j++) printf("%d %d\n",two[j].B,loc);
			break;
		}
	}

	return 0;
}