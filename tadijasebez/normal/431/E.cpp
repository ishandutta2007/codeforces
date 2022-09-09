#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb double
const int N=200050;
int ls[N],rs[N],tsz,root,pri[N],val[N],sz[N];
ll sum[N];
mt19937 rng(time(0));
void pull(int c){if(!c)return;sum[c]=sum[ls[c]]+val[c]+sum[rs[c]];sz[c]=sz[ls[c]]+1+sz[rs[c]];}
int nnd(int v){++tsz;pri[tsz]=rng();val[tsz]=v;pull(tsz);return tsz;}
void rot_l(int &c){int a=rs[c],b=ls[a];rs[c]=b;ls[a]=c;pull(c);pull(a);c=a;}
void rot_r(int &c){int a=ls[c],b=rs[a];ls[c]=b;rs[a]=c;pull(c);pull(a);c=a;}
void ins(int &c,int v){
	if(!c)c=nnd(v);
	else{
		if(val[c]<=v){
			ins(rs[c],v);
			if(pri[rs[c]]>pri[c])rot_l(c);
			else pull(c);
		}else{
			ins(ls[c],v);
			if(pri[ls[c]]>pri[c])rot_r(c);
			else pull(c);
		}
	}
}
void del(int &c,int v){
	if(val[c]==v){
		if(!ls[c])c=rs[c];
		else if(!rs[c])c=ls[c];
		else if(pri[ls[c]]>pri[rs[c]])rot_r(c),del(rs[c],v);
		else rot_l(c),del(ls[c],v);
	}else if(val[c]<v)del(rs[c],v);
	else del(ls[c],v);
	pull(c);
}
pair<ll,pair<int,int>> ans;
void get(int c,ll v,ll s=0,int k=0){
	if(!c)return;
	ll now=(ll)val[c]*(k+sz[ls[c]]+1)-(s+sum[ls[c]]+val[c]);
	if(now<=v){
		s+=sum[ls[c]]+val[c];
		k+=sz[ls[c]]+1;
		ans={now,{k,val[c]}};
		get(rs[c],v,s,k);
	}else get(ls[c],v,s,k);
}
int p[N];
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]),ins(root,p[i]);
	while(q--){
		int t;
		scanf("%i",&t);
		if(t==1){
			int i,x;
			scanf("%i %i",&i,&x);
			del(root,p[i]);
			p[i]=x;
			ins(root,p[i]);
		}else{
			ll v;
			scanf("%lld",&v);
			get(root,v);
			ldb res=ans.second.second+(ldb)(v-ans.first)/ans.second.first;
			printf("%.10f\n",res);
		}
	}
	return 0;
}