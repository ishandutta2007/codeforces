#include <bits/stdc++.h>
using namespace std;

double ans = 1e10;
int n, m, i, x, y;

int main(){
	for(scanf("%d%d",&n,&m),i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		double tmp = (x/(double)y)*m;
		ans = min(ans,tmp);
	}
	printf("%.7lf\n",ans);
	return 0;
}