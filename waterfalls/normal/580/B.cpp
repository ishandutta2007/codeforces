#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

int n,d;
pair<int,long long> f[100013];

int main() {
	scanf("%d%d",&n,&d);
	for (int i=0;i<n;i++) scanf("%d%lld",&f[i].A,&f[i].B);
	sort(f,f+n);
	for (int i=1;i<n;i++) f[i].B+=f[i-1].B;
	long long ans = 0;
	int on = 0;
	for (int i=0;i<n;i++) {
		while (on<n && f[on].A-d<f[i].A) on+=1;
		ans = max(ans,f[on-1].B-(i ? f[i-1].B : 0));
	}
	printf("%lld\n",ans);

	return 0;
}