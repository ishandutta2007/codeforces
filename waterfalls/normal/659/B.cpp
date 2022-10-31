#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<pair<int,string> > has[10013];
char buff[20];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int r,p;
		scanf(" %s%d%d",&buff,&r,&p);
		has[r].push_back(MP(p,string(buff)));
	}
	for (int i=1;i<=m;i++) {
		sort(has[i].begin(),has[i].end());
		reverse(has[i].begin(),has[i].end());
		if (has[i].size()>2 && has[i][1].A==has[i][2].A) printf("?\n");
		else printf("%s %s\n",has[i][0].B.c_str(),has[i][1].B.c_str());
	}

	return 0;
}