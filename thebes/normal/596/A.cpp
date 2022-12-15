#include <bits/stdc++.h>
using namespace std;

int n, i, j; pair<int,int> p[5];

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d%d",&p[i].first,&p[i].second);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(p[i].first!=p[j].first&&p[i].second!=p[j].second){
				printf("%d\n",abs(p[j].second-p[i].second)*abs(p[j].first-p[i].first));
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}