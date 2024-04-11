#include <cstdio>
#include <algorithm>

typedef long long lli;
int n,cache[1<<20];
lli adj[40];
double k;

int main() {
	int val;
	scanf("%d %lf",&n,&k);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		scanf("%d",&val);
		if(i==j) val=1;
		adj[i]|=((long long)val<<j);
	}
	
	for(int i=1;i<(1<<(std::max(0,n-20)));i++) {
		lli state=i;
		int cnt=0;
		for(int j=0;j<std::max(0,n-20);j++) {
			if(i&(1<<j)) state&=adj[j+20]>>20,cnt++;
		}
		if(state==i) cache[i]=cnt;
	}
	for(int i=1;i<(1<<std::max(0,n-20));i++) {
		for(int j=0;j<std::max(0,n-20);j++) {
			if(i&(1<<j)) cache[i]=std::max(cache[i],cache[i^(1<<j)]);
		}
	}

	int mx=0;
	for(int i=0;i<(1<<std::min(n,20));i++) {
		int cnt=0;
		lli fs=i,bs=(1<<std::max(0,n-20))-1;
		for(int j=0;j<std::min(n,20);j++) {
			if(i&(1<<j)) {
				fs&=adj[j]&((1<<(std::min(n,20)))-1);
				bs&=adj[j]>>20;
				cnt++;
			}
		}
		if(fs==i) {
			mx=std::max(mx,cnt+cache[bs]);
		}
	}
	printf("%.7lf\n",k*k*(mx-1)/(double)(2*mx));
	
	return 0;
}