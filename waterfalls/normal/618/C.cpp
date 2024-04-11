#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x1,y1;
ll x[100013], y[100013];

ll dist(int i) { return x[i]*x[i]+y[i]*y[i]; }
bool line(int a, int b) {
	if (x[a]==0 && x[b]==0) return true;
	return (x[a]*y[b]==x[b]*y[a]);
}

int main() {
	scanf("%d",&n);
	n-=1;
	scanf("%lld%lld",&x1,&y1);
	for (int i=1;i<=n;i++) {
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]-=x1;
		y[i]-=y1;
	}
	int best = 1;
	for (int i=1;i<=n;i++) {
		if (dist(i)<dist(best)) best = i;
	}
	int best2 = 1;
	while (best2==best || line(best,best2)) best2+=1;
	for (int i=1;i<=n;i++) {
		if (i!=best && !line(best,i)) {
			if (dist(i)<dist(best2)) {
				best2 = i;
			}
		}
	}
	printf("%d %d %d\n",1,best+1,best2+1);

	return 0;
}