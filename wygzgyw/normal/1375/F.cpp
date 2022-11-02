#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll a,b,c,d[4],r;
int id[4],dy[4],x;
bool cmp(int x,int y) {
	return d[x]<d[y];
}
int main() {
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("First\n"); fflush(stdout);
	d[1]=a,d[2]=b,d[3]=c;
	id[1]=1,id[2]=2,id[3]=3;
	sort(id+1,id+4,cmp);
	a=d[id[1]],b=d[id[2]],c=d[id[3]];
	dy[id[1]]=1,dy[id[2]]=2,dy[id[3]]=3;
	while (1) {
		r=c*2-a-b;
		printf("%lld\n",r); fflush(stdout);
		scanf("%d",&x);
		x=dy[x];
		if (x==1) {
			printf("%lld\n",c-b); fflush(stdout);
			scanf("%d",&x); break;
		} else if (x==2) {
			printf("%lld\n",c-a); fflush(stdout);
			scanf("%d",&x); break;
		} else {
			c+=r;
		}
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/