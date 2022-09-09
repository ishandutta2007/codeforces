#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000000;
struct Matrix{
	int a[2][2];
	Matrix(){a[0][0]=a[1][0]=a[0][1]=a[1][1]=0;}
	void id(){a[0][0]=a[1][1]=1;}
};
struct Vector{
	int a[2];
	Vector(){a[0]=a[1]=0;}
};
Matrix operator * (Matrix A,Matrix B){
	Matrix ans;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				ans.a[i][j]=(ans.a[i][j]+(ll)A.a[i][k]*B.a[k][j])%mod;
	return ans;
}
Vector operator * (Vector A,Matrix B){
	Vector ans;
	for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)
			ans.a[j]=(ans.a[j]+(ll)A.a[k]*B.a[k][j])%mod;
	return ans;
}
Vector operator + (Vector A,Vector B){
	Vector ans;
	ans.a[0]=A.a[0]+B.a[0];if(ans.a[0]>=mod)ans.a[0]-=mod;
	ans.a[1]=A.a[1]+B.a[1];if(ans.a[1]>=mod)ans.a[1]-=mod;
	return ans;
}
const int N=200050;
const int M=2*N;
Matrix fib[N];
int pre[N];
struct Node{
	Vector v;
	int sz,lzy;
	Node(){v=Vector();sz=lzy=0;}
	void Add(int x){
		v.a[0]+=(ll)pre[sz-1]*x%mod;if(v.a[0]>=mod)v.a[0]-=mod;
		v.a[1]+=(ll)(pre[sz]-pre[0])*x%mod;if(v.a[1]>=mod)v.a[1]-=mod;
		lzy+=x;
		if(lzy>=mod)lzy-=mod;
	}
	void Set(int x){
		v.a[0]=v.a[1]=x;
		sz=1;
	}
};
Node operator + (Node a,Node b){
	Node ans;
	ans.v=a.v+(b.v*fib[a.sz]);
	ans.sz=a.sz+b.sz;
	return ans;
}
Node node[M];
int ls[M],rs[M],tsz,root;
void push(int c){
	if(node[c].lzy){
		node[ls[c]].Add(node[c].lzy);
		node[rs[c]].Add(node[c].lzy);
		node[c].lzy=0;
	}
}
void Set(int &c,int ss,int se,int qi,int val){
	if(!c)c=++tsz;
	if(ss==se){node[c].Set(val);return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Add(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){node[c].Add(x);return;}
	push(c);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return node[c];
	push(c);
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
void _(){
	fib[0].id();
	fib[1].a[0][0]=1;
	fib[1].a[1][0]=1;
	fib[1].a[0][1]=1;
	fib[1].a[1][1]=0;
	for(int i=2;i<N;i++)fib[i]=fib[i-1]*fib[1];
	pre[0]=1;pre[1]=1;
	for(int i=2;i<N;i++)pre[i]=(pre[i-1]+pre[i-2])%mod;
	for(int i=1;i<N;i++)pre[i]=(pre[i]+pre[i-1])%mod;
}
int main(){
	_();
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1,x;i<=n;i++)scanf("%i",&x),Set(root,1,n,i,x);
	while(q--){
		int t;
		scanf("%i",&t);
		if(t==1){
			int i,x;
			scanf("%i %i",&i,&x);
			Set(root,1,n,i,x);
		}else if(t==2){
			int l,r;
			scanf("%i %i",&l,&r);
			printf("%i\n",Get(root,1,n,l,r).v.a[1]);
		}else if(t==3){
			int l,r,x;
			scanf("%i %i %i",&l,&r,&x);
			Add(root,1,n,l,r,x);
		}
	}
	return 0;
}