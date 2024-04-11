#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m,k,p;
int h[100013];
int a[100013];

int num[100013];

priority_queue<pair<ll,int> > dead;
priority_queue<pair<ll,int> > small;
pair<int,pair<ll,int> > go(int i, ll K) {
	ll will = K-1LL*m*a[i]+1LL*p*num[i];
	if (will<0) dead.push(MP(-K/a[i]-num[i],i));
	else if (will<h[i]) small.push(MP((h[i]-will+p-1)/p,i));
}
bool check(ll K) {
	while (dead.size()>0) dead.pop();
	while (small.size()>0) small.pop();
	for (int i=1;i<=n;i++) {
		num[i] = 0;
		go(i,K);
	}
	for (int i=1;i<=m;i++) {
		if (dead.size()>0 && -dead.top().A<i) return false;
		for (int j=0;j<k;j++) {
			int which;
			if (dead.size()>0) {
				which = dead.top().B;
				dead.pop();
			} else if (small.size()>0) {
				which = small.top().B;
				small.pop();
			} else break;
			num[which]+=1;
			go(which,K);
		}
	}
	return (dead.size()==0 && small.size()==0);
}

int main() {
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (int i=1;i<=n;i++) scanf("%d%d",&h[i],&a[i]);
	ll low = 0;
	ll high = 1e13;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	printf("%lld\n",high);

	return 0;
}