#include <bits/stdc++.h>
using namespace std;

#define left left_
#define right right_

int n,h;
double p;
int x[2013];
int right[2013], left[2013];
double prob[2013][2013][2][2];

void makeside() {
	for (int i=1;i<=n;i++) {
		int far = x[i]+h;
		int on = i+1;
		while (x[on]<far) {
			far = x[on]+h;
			on+=1;
		}
		right[i] = on-1;
		far = x[i]-h;
		on = i-1;
		while (x[on]>far) {
			far = x[on]-h;
			on-=1;
		}
		left[i] = on+1;
	}
}

int main() {
	scanf("%d%d%lf",&n,&h,&p);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	x[0] = -1e9; x[n+1] = 1e9;
	makeside();
	prob[1][n][0][0] = 1;
	double ans = 0;
	for (int i=1;i<=n;i++) for (int j=n;j>=i;j--) {
		for (int a=0;a<2;a++) for (int b=0;b<2;b++) {
			if (prob[i][j][a][b]==0) continue;
			int l = a ? x[i-1]+h : x[i-1];
			int r = b ? x[j+1]-h : x[j+1];

			double cur = 0.5*p*prob[i][j][a][b];
			prob[i+1][j][0][b]+=cur;
			ans+=cur*min(h,x[i]-l);

			cur = 0.5*(1-p)*prob[i][j][a][b];
			int go = min(right[i],j);
			prob[go+1][j][1][b]+=cur;
			ans+=cur*(min(r,x[go]+h)-x[i]);

			cur = 0.5*(1-p)*prob[i][j][a][b];
			prob[i][j-1][a][0]+=cur;
			ans+=cur*min(h,r-x[j]);

			cur = 0.5*p*prob[i][j][a][b];
			go = max(left[j],i);
			prob[i][go-1][a][1]+=cur;
			ans+=cur*(x[j]-max(l,x[go]-h));
		}
	}
	printf("%1.9f\n",ans);

	return 0;
}