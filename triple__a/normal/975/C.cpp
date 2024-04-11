#include "bits/stdc++.h"
using namespace std;

const int maxn=200007;
int n,q;
long long a[maxn],s[maxn];
int mids(int l,int r,long long key){
	if (l==r) return l;
	int md=(l+r)>>1;
	if (key<s[md+1]) return mids(l,md,key);
	else return mids(md+1,r,key); 
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	s[0]=0;
	for (int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	long long st=0;
	while (q--){
		long long r;
		scanf("%lld",&r);
		st+=r;
		if (st>=s[n]){
			printf("%d\n",n);
			st=0;
			continue;
		}
		long long t=mids(0,n,st);
		printf("%d\n",n-t);
	}
	return 0;
}