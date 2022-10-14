#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int S=2000;
int n,q,a[N],p[N],x[N],y[N],b[N],L=1,R,K,ans[N];
struct Query{
	int l,r,k,t,i;
	Query(int a=0,int b=0,int c=0,int d=0,int e=0){l=a,r=b,k=c,t=d,i=e;}
	bool operator < (Query b){
		if(l/S!=b.l/S)return l<b.l;
		if(t/S!=b.t/S)return t<b.t;
		return r<b.r;
	}
}Q[N];
int ord[N],cnt1[N],cnt2[N],ss[N],se[N];
void Add(int x){
	ord[se[cnt1[x]]]=cnt1[x]+1;
	se[cnt1[x]]--;
	ss[++cnt1[x]]--;
}
void Del(int x){
	ord[ss[cnt1[x]]]=cnt1[x]-1;
	ss[cnt1[x]]++;
	se[--cnt1[x]]++;
}
void Upd(int i){
	if(p[i]>=L&&p[i]<=R)Del(a[p[i]]),Add(x[i]);
	a[p[i]]=x[i];
}
void Err(int i){
	if(p[i]>=L&&p[i]<=R)Del(a[p[i]]),Add(y[i]);
	a[p[i]]=y[i];
}
int main() {
	scanf("%i%i",&n,&q);
	int qs=0,m=0;
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		b[i]=a[i];
	}
	for(int i=1;i<=q;i++){
		int t;
		scanf("%i",&t);
		if(t==1){
			int l,r,k;
			scanf("%i%i%i",&l,&r,&k);
			qs++;
			Q[qs]=Query(l,r,k,m,qs);
		}else{
			m++;
			scanf("%i%i",&p[m],&x[m]);
			y[m]=b[p[m]];
			b[p[m]]=x[m];
		}
	}
	sort(Q+1,Q+qs+1);
	for(int i=0;i<=n;i++)ss[i]=n+1,se[i]=n;
	ss[0]=1;
	for(int i=1;i<=qs;i++){
		while(L>Q[i].l)Add(a[--L]);
		while(R<Q[i].r)Add(a[++R]);
		while(L<Q[i].l)Del(a[L++]);
		while(R>Q[i].r)Del(a[R--]);
		while(K<Q[i].t)Upd(++K);
		while(K>Q[i].t)Err(K--);
		int id=Q[i].i;
		ans[id]=1e9;
		for(int j=1;j+Q[i].k<=n+1;j=se[ord[j]]+1){
			if(ord[j])ans[id]=min(ans[id],ord[j+Q[i].k-1]-ord[j]);
		}
	}
	for(int i=1;i<=qs;i++)printf("%i\n",(ans[i]==1e9?-1:ans[i]));
	return 0;
}