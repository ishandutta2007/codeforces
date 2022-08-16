#include"stdio.h"
#include"algorithm"
using namespace std;
#define N 500000
int vel[N], pos[N];
int main() {
	long long count = 0;
	int n;
	scanf("%d", &n);
	int num = 0;
	for(int i=0; i<n; i++) {
		scanf("%d%d",&pos[i], &vel[i]);
		if(vel[i]<0)num++; else count += num;
	}
	double low = 0, high = 1e9+10;
	while(low<high-1e-10 and (high<1 or low<high*(1-1e-10))) {
		double mid = (high + low)/2;
		double max_pos = -1e20;
		bool passed = 0;
		for(int i=0; i<n; i++) if(vel[i]<0){ if(max_pos > pos[i] + mid * vel[i]){passed = 1; break;} } else max_pos = max(max_pos, pos[i] + mid * vel[i]);
		if(passed) high = mid; else low = mid;
	}
	if (low > 1e9+0.01) printf("%d\n", -1);
	else printf("%.15f\n", low);
}