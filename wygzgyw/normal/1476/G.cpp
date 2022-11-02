#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,a[maxn],mx,N=100000;
struct node { int l,r,x,id,t; } Q[maxn];
struct change { int x,y; } C[maxn];
int q,ans[maxn],block,B,L,R;
vector<int> sp;
bool cmp(node A,node B) {
	if (A.l/block!=B.l/block) return A.l<B.l;
	if (A.r/block!=B.r/block) {
		if ((A.l/block)&1) return A.r<B.r;
		return A.r>B.r;
	}
	return A.t<B.t;
}
int cnt[maxn],buc[maxn];
void add(int x) {
	buc[cnt[x]+N]--;
	cnt[x]++;
	buc[cnt[x]+N]++;
}
void del(int x) {
	buc[cnt[x]+N]--;
	cnt[x]--;
	buc[cnt[x]+N]++;
}
void update(int x) {
	if (L<=C[x].x&&C[x].x<=R) del(a[C[x].x]),add(C[x].y);
	swap(a[C[x].x],C[x].y);
}
int tot,t2,s1[maxn],s2[maxn],s3[maxn];
int query(int x) {
	tot=t2=0;
	for (int i=1;i<=B;i++)
		if (buc[i+N]) {
			tot++;
			s1[tot]=i,s2[tot]=s2[tot-1]+buc[i+N];
		}
	for (int i=0,u;i<sp.size();i++) {
		u=sp[i];
		if (cnt[u]>B) s3[++t2]=cnt[u];
	}
	sort(s3+1,s3+t2+1);
	for (int i=1;i<=t2;i++) tot++,s1[tot]=s3[i],s2[tot]=s2[tot-1]+1;
	int pos=0,res=n+1;
	for (int i=1;i<=tot;i++) {
		while (s2[i]-s2[pos+1]>=x) pos++;
		if (s2[i]-s2[pos]>=x) res=min(res,s1[i]-s1[pos+1]);
	}
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	block=pow(n*1.0,2.0/3);
	B=sqrt(n*1.0);
	for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++,mx=max(mx,a[i]);
	int op,cur=0;
	
	for (int i=1;i<=m;i++) {
		read(op);
		if (op==1) {
			q++;
			read(Q[q].l),read(Q[q].r),read(Q[q].x);
			Q[q].id=q,Q[q].t=cur;
		} else {
			cur++;
			read(C[cur].x),read(C[cur].y);
			mx=max(mx,C[cur].y);
			cnt[C[cur].y]++;
		}
	}
	for (int i=1;i<=mx;i++) if (cnt[i]>B) sp.push_back(i);
	memset(cnt,0,sizeof(cnt));
	sort(Q+1,Q+q+1,cmp);
	L=1,R=0;
	int t=0;
	for (int i=1;i<=q;i++) {
		while (L<Q[i].l) del(a[L]),L++;
		while (L>Q[i].l) L--,add(a[L]);
		while (R<Q[i].r) R++,add(a[R]);
		while (R>Q[i].r) del(a[R]),R--;
		while (t<Q[i].t) t++,update(t);
		while (t>Q[i].t) update(t),t--;
		ans[Q[i].id]=query(Q[i].x);
	}
	for (int i=1;i<=q;i++) {
		if (ans[i]<=n) printf("%d\n",ans[i]);
		else puts("-1");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/