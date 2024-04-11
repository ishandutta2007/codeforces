#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=500050;
const int M=2*N;
const ll inf=9e18;
int ls[M],rs[M],tsz,root;
ll lzy[M],mn[M];
void upd(int x,ll f){mn[x]+=f;lzy[x]+=f;}
void push(int x){if(lzy[x])upd(ls[x],lzy[x]),upd(rs[x],lzy[x]),lzy[x]=0;}
void Build(int &c,int ss,int se){
	c=++tsz;
	if(ss==se){mn[c]=ss==0?0:inf;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c,int ss,int se,int qi,ll f){
	if(ss==se){mn[c]=min(mn[c],f);return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
void Add(int c,int ss,int se,int qs,int qe,ll f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){upd(c,f);return;}
	push(c);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
}
ll Get(int c,int ss,int se,int qi){
	if(ss==se)return mn[c];
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid)return Get(ls[c],ss,mid,qi);
	else return Get(rs[c],mid+1,se,qi);
}
int a[N],p[N],b[N],pos[N];
int main(){
	int n,m;
	scanf("%i",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]);
	scanf("%i",&m);
	for(int i=1;i<=m;i++)scanf("%i",&b[i]),pos[b[i]]=i;
	Build(root,0,n);
	for(int i=1;i<=n;i++){
		ll now;
		if(pos[a[i]])now=Get(root,0,n,b[pos[a[i]]-1]);
		if(p[i]>0)Add(root,0,n,0,a[i]-1,p[i]);
		else Add(root,0,n,0,n,p[i]);
		if(pos[a[i]])Set(root,0,n,a[i],now);
	}
	ll ans=Get(root,0,n,b[m]);
	if(ans>1e17)printf("NO\n");
	else{
		printf("YES\n");
		printf("%lld\n",ans);
	}
	return 0;
}