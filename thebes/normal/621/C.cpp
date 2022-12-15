#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
double ans, p[MN];
int N, P, i, x, y;

int main(){
	for(scanf("%d%d",&N,&P),i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		double c = (y/P)-((x-1)/P);
		p[i] = 1.0-c/(double)(y-x+1);
	}
	for(i=1;i<=N;i++)
		ans += 1.0-p[i]*p[(i==N)?1:i+1];
	printf("%.6lf\n",ans*2000.0);
	return 0;
}