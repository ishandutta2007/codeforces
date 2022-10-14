#include <bits/stdc++.h>
using namespace std;
const int N=200050,M=120*N;
const int mod=1e9+1;
int n,root=1,ls[M],rs[M],tsz=1,mn[M],mx[M],lzy[M];
void make(int&c,int ss,int se){
	c=++tsz;mn[c]=ss;mx[c]=se;
}
void push(int c,int ss,int mid,int se){
	mn[c]+=lzy[c];
	mx[c]+=lzy[c];
	if(ss==se){
		lzy[c]=0;
		return;
	}
	if(!ls[c])make(ls[c],ss,mid);
	if(!rs[c])make(rs[c],mid+1,se);
	lzy[ls[c]]+=lzy[c];
	lzy[rs[c]]+=lzy[c];
	lzy[c]=0;
}
int Left(int c,int ss,int se,int qi){
	int mid=ss+se>>1;
	push(c,ss,mid,se);
	if(ss==se)return ss;
	if(mx[ls[c]]+lzy[ls[c]]>=qi)return Left(ls[c],ss,mid,qi);
	else return Left(rs[c],mid+1,se,qi);
}
int Right(int c,int ss,int se,int qi){
	int mid=ss+se>>1;
	push(c,ss,mid,se);
	if(ss==se)return ss;
	if(mn[rs[c]]+lzy[rs[c]]<=qi)return Right(rs[c],mid+1,se,qi);
	else return Right(ls[c],ss,mid,qi);
}
void Set(int c,int ss,int se,int qs,int qe,int x){
	int mid=ss+se>>1;
	if(ss>se||ss>qe||se<qs)return push(c,ss,mid,se);
	if(qs<=ss&&se<=qe){
		lzy[c]+=x;
		push(c,ss,mid,se);
		return;
	}
	push(c,ss,mid,se);
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	mn[c]=mn[ls[c]];
	mx[c]=mx[rs[c]];
}
int Get(int c,int ss,int se,int qi){
	int mid=ss+se>>1;
	push(c,ss,mid,se);
	if(ss==se)return mn[c];
	if(qi<=mid)return Get(ls[c],ss,mid,qi);
	else return Get(rs[c],mid+1,se,qi);
}
int main(){
	scanf("%i",&n);
	mx[root]=1e9;
	int last=0;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%i",&t);
		if(t<mn[root])lzy[root]--;
		else if(t>mx[root])lzy[root]++;
		else{
			int L=Left(root,0,1e9,t);
			int R=Right(root,0,1e9,t);
			Set(root,0,1e9,0,L-1,1);
			Set(root,0,1e9,R+1,1e9,-1);
		}
		int k;
		scanf("%i",&k);
		while(k--){
			int x;
			scanf("%i",&x);
			x=(x+last)%mod;
			last=Get(root,0,1e9,x);
			printf("%i\n",last);
		}
	}
	return 0;
}