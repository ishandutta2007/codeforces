#include <bits/stdc++.h>
using namespace std;

int n,k;
int v[20][1000013], c[20][1000013];
int high[1000013];

int imax(int a, int b) { return max(a,b); }
int imin(int a, int b) { return min(a,b); }

void process(int st[][1000013], int (*f)(int,int)) {
	high[0] = -1;
	for (int i=1;i<1000013;i++) {
		high[i] = high[i-1]+1;
		if ((1<<high[i])>i) high[i]-=1;
	}
	for (int i=1;i<20;i++) {
		for (int j=1;j<=n-(1<<i)+1;j++) {
			st[i][j] = f(st[i-1][j],st[i-1][j+(1<<i)/2]);
		}
	}
}
int query(int st[][1000013], int a, int b, int (*f)(int,int)) {
	int d = high[b-a+1];
	return f(st[d][a],st[d][b-(1<<d)+1]);
}

int calc(int l) {
	int low = l-1;
	int high = n;
	while (high-low>1) {
		int mid = (low+high+1)/2;
		int one = 100*query(v,l,mid,imax);
		int two = query(c,l,mid,imin);
		if (one>=two) high = mid;
		else low = mid;
	}
	int ans = 0;
	for (int d=-2;d<=2;d++) {
		if (l<=high+d && high+d<=n) {
			ans = max(ans,min(100*query(v,l,high+d,imax),query(c,l,high+d,imin)));
		}
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&v[0][i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[0][i]);
	process(v,imax);
	process(c,imin);
	vector<int> has;
	for (int i=1;i<=n;i++) has.push_back(calc(i));
	sort(has.begin(),has.end());
	double ans = 0;
	double chance = 1;
	for (int i=0;i<=n-k;i++) {
		ans+=chance*k/(n-i)*has[i];
		chance*=1.*(n-i-k)/(n-i);
	}
	printf("%1.9f\n",ans);

    return 0;
}