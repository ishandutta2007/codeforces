#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(6e5)+10;
struct node {
	int aL,aR,bL,bR,v;
} d[maxn];
int k,q,tot,s1[(1<<16)+10],s2[(1<<16)+10],ans1[(1<<16)+10],ans2[(1<<16)+10];
pair<int,int> get(ll x) { return make_pair(x&((1<<k)-1),x>>k); }
int main() {
	//freopen("1.txt","r",stdin);
	read(k),read(q);
	ll l,r; int v;
	//puts("HI");
	while (q--) {
		read(l),read(r),read(v);
		pair<int,int> a=get(l),b=get(r);
		//printf("%d %d %d %d\n",a.first,a.second,b.first,b.second);	
		if (a.second==b.second) d[++tot]=(node){a.first,b.first,a.second,a.second,v};
		else {
			d[++tot]=(node){a.first,(1<<k)-1,a.second,a.second,v};
			//printf(" %d\n",d[tot].aR);
			d[++tot]=(node){0,b.first,b.second,b.second,v};
			if (a.second+1<b.second) d[++tot]=(node){0,(1<<k)-1,a.second+1,b.second-1,v};
		}
	}
	int A,B;
	for (int i=0;i<16;i++) {
		memset(s1,0,sizeof(s1)),memset(s2,0,sizeof(s2));
		for (int j=1;j<=tot;j++) if (d[j].v&(1<<i)) {
			s1[d[j].aL]++,s1[d[j].aR+1]--;
			s2[d[j].bL]++,s2[d[j].bR+1]--;
			//printf("%d %d %d %d\n",d[j].aL,d[j].aR,d[j].bL,d[j].bR);
		}
		for (int j=1;j<(1<<k);j++) s1[j]+=s1[j-1],s2[j]+=s2[j-1];
		for (int j=0;j<(1<<k);j++) {
			if (s1[j]) ans1[j]+=(1<<i),s1[j]=1;
			if (s2[j]) ans2[j]+=(1<<i),s2[j]=1;
		}
		//for (int j=0;j<(1<<k);j++) if (s2[j]) printf("%d ",j); puts("");
		for (int j=1;j<(1<<k);j++) s1[j]+=s1[j-1],s2[j]+=s2[j-1];
		for (int j=1;j<=tot;j++) {
			if (d[j].v&(1<<i)) continue;
			A=s1[d[j].aR]; if (d[j].aL) A-=s1[d[j].aL-1];
			B=s2[d[j].bR]; if (d[j].bL) B-=s2[d[j].bL-1];
			//printf(" %d\n",s2[d[j].bR]);
			if (A&&B) { puts("impossible"); return 0; }
		}
	}
	puts("possible");
	for (int i=0;i<(1<<k);i++) printf("%d\n",ans1[i]);
	for (int i=0;i<(1<<k);i++) printf("%d\n",ans2[i]);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/