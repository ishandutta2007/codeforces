#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=75050;
const int M=150*N;
const int K=200050;
ll sum[M],mul[M];
int ls[M],rs[M],root[N],tsz;
void Set(int p,int&c,int ss,int se,int qs,int qe,int a,int b){
    c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p];mul[c]=mul[p];
	if(ss>se||ss>qe||se<qs)return;
	if(qs<=ss&&se<=qe){
		sum[c]+=a;
		mul[c]+=b;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[p],ls[c],ss,mid,qs,qe,a,b);
	Set(rs[p],rs[c],mid+1,se,qs,qe,a,b);
}
ll sum_ans,mul_ans;
void Get(int c,int ss,int se,int qi,int op){
	sum_ans+=sum[c]*op;
	mul_ans+=mul[c]*op;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Get(ls[c],ss,mid,qi,op);
	else Get(rs[c],mid+1,se,qi,op);
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++){
		int x1,x2,y1,a,b,y2;
		scanf("%i%i%i%i%i%i",&x1,&x2,&y1,&a,&b,&y2);
        root[i]=root[i-1];
        Set(root[i],root[i],0,K,0,x1,y1,0);
        Set(root[i],root[i],0,K,x1+1,x2,b,a);
        Set(root[i],root[i],0,K,x2+1,K,y2,0);
    }
    int m;scanf("%i",&m);
    ll last=0;
    while(m--){
        int l,r,x;scanf("%i%i%i",&l,&r,&x);
        x=(x+last)%(int)(1e9);
        x=min(x,K);
        sum_ans=mul_ans=0;
        Get(root[r],0,K,x,1);
        Get(root[l-1],0,K,x,-1);
        last=sum_ans+mul_ans*x;
        printf("%lld\n",last);
    }
	return 0;
}