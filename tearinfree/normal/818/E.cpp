#include <cstdio>
#include <algorithm>

typedef long long lli;
const int MAX=1<<17;
int n;
lli k,arr[100000],tree[1<<18];

lli Mul(int node, int st, int fi, int le, int ri) {
	if(fi<le||st>ri) return 1;
	else if(le<=st&&fi<=ri) return tree[node];
	else return Mul(node*2,st,(st+fi)/2,le,ri)*Mul(node*2+1,(st+fi)/2+1,fi,le,ri)%k;
}
int main() {
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",arr+i),tree[MAX+i]=arr[i];
	for(int i=MAX-1;i;i--) tree[i]=tree[i<<1]*tree[(i<<1)+1]%k;

	int le=0,ri;
	lli cnt=0;
	for(ri=0;ri<n;ri++) {
		while(le<=ri&&Mul(1,0,MAX-1,le,ri)==0) le++;
		cnt+=(ri-le+1);
	}
	cnt=(long long)(n)*(n+1)/2-cnt;
	printf("%lld\n",cnt);

	return 0;
}