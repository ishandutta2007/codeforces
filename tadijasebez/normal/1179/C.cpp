#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
const int M=2*N;
int ls[M],rs[M],tsz,root,lzy[M],mx[M];
void upd(int c,int x){mx[c]+=x;lzy[c]+=x;}
void push(int c){if(lzy[c])upd(ls[c],lzy[c]),upd(rs[c],lzy[c]),lzy[c]=0;}
void Build(int &c,int ss,int se){
	c=++tsz;lzy[c]=mx[c]=0;
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){upd(c,f);return;}
	push(c);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
int Get(int c,int ss,int se){
	if(mx[c]<=0)return -1;
	if(ss==se)return ss;
	push(c);
	int mid=ss+se>>1;
	if(mx[rs[c]]>0)return Get(rs[c],mid+1,se);
	return Get(ls[c],ss,mid);
}
int a[N],b[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	Build(root,1,N);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),Add(root,1,N,1,a[i],1);
	for(int i=1;i<=m;i++)scanf("%i",&b[i]),Add(root,1,N,1,b[i],-1);
	int q;
	scanf("%i",&q);
	while(q--){
		int t,i,x;
		scanf("%i %i %i",&t,&i,&x);
		if(t==1)Add(root,1,N,1,a[i],-1),Add(root,1,N,1,x,1),a[i]=x;
		else Add(root,1,N,1,b[i],1),Add(root,1,N,1,x,-1),b[i]=x;
		printf("%i\n",Get(root,1,N));
	}
	return 0;
}