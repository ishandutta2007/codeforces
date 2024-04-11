#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=32*N;
const int lim=1e9;
int ls[M],rs[M],tsz,root,mx[M],sum[M];
void Max(int &c,int ss,int se,int qi,int x){
	if(!c)c=++tsz;
	mx[c]=max(mx[c],x);
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Max(ls[c],ss,mid,qi,x);
	else Max(rs[c],mid+1,se,qi,x);
}
void Add(int &c,int ss,int se,int qi,int x){
	if(!c)c=++tsz;
	sum[c]+=x;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Add(ls[c],ss,mid,qi,x);
	else Add(rs[c],mid+1,se,qi,x);
}
int GetS(int c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return 0;
	if(qs<=ss && qe>=se)return sum[c];
	int mid=ss+se>>1;
	return GetS(ls[c],ss,mid,qs,qe)+GetS(rs[c],mid+1,se,qs,qe);
}
int GetM(int c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return 0;
	if(qs<=ss && qe>=se)return mx[c];
	int mid=ss+se>>1;
	return max(GetM(ls[c],ss,mid,qs,qe),GetM(rs[c],mid+1,se,qs,qe));
}
int ord[N],r[N],a[N],sz[N],x[N],y[N],rnk[N],qrd[N],ans[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++)scanf("%i",&r[i]);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),ord[i]=i;
	sort(ord+1,ord+1+n,[&](int i,int j){return r[i]<r[j];});
	for(int i=1,j;i<=n;i=j){
		for(j=i;j<=n && r[ord[i]]==r[ord[j]];j++){
			int idx=ord[j];
			Add(root,1,lim,a[idx],1);
		}
		for(int z=i;z<j;z++){
			int idx=ord[z];
			sz[idx]=GetS(root,1,lim,a[idx]-k,a[idx]+k);
		}
	}
	for(int i=1;i<=tsz;i++)ls[i]=rs[i]=0;
	root=tsz=0;
	int ptr=n;
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++)scanf("%i %i",&x[i],&y[i]),rnk[i]=max(r[x[i]],r[y[i]]),qrd[i]=i;
	sort(qrd+1,qrd+1+q,[&](int i,int j){return rnk[i]>rnk[j];});
	for(int i=1;i<=q;i++){
		int qi=qrd[i];
		while(ptr>0 && r[ord[ptr]]>=rnk[qi]){
			Max(root,1,lim,a[ord[ptr]],sz[ord[ptr]]);
			ptr--;
		}
		int L=min(a[x[qi]],a[y[qi]]);
		int R=max(a[x[qi]],a[y[qi]]);
		tie(L,R)=make_pair(R-k,L+k);
		ans[qi]=GetM(root,1,lim,L,R);
		if(!ans[qi])ans[qi]=-1;
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}