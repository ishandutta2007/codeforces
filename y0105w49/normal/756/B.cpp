#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);


const int N=1<<20;
int t[N];
int z[N];

int main() {
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",t+i);

	z[0]=0;
	for(int i=0;i<n;i++) {
		z[i+1]=z[i]+20;
		int a1=upper_bound(t,t+i,t[i]-90)-t;
		int a2=upper_bound(t,t+i,t[i]-1440)-t;
		z[i+1]=min(z[i+1],z[a1]+50);
		z[i+1]=min(z[i+1],z[a2]+120);
		printf("%d\n",z[i+1]-z[i]);
	}
}