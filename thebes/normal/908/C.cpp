#include <bits/stdc++.h>
using namespace std;

struct c{double x,y;}p[1004];
int N, R, i, j, x; double m;

int main(){
	for(scanf("%d%d",&N,&R),i=0;i<N;i++){
		scanf("%d",&x); p[i].x = x; m=R;
		for(j=0;j<i;j++){
			if(abs(p[j].x-p[i].x)>2*R) continue;
			double dx = abs(p[j].x-p[i].x);
			double dy = sqrt(4*R*R-dx*dx);
			m = max(m,dy+p[j].y);
		}
		printf("%.7lf\n",m);
		p[i].y = m;
	}
	return 0;
}