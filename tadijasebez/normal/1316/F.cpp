#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int mod=1e9+7;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}
const int N=300050;
int pw2[N];
struct Node{
	int l_sum,r_sum,sz,ans;
	Node(){}
	Node(int x){sz=1;l_sum=r_sum=x;ans=0;}
};
int mer_cnt;
Node operator+(Node a,Node b){

	//++mer_cnt;

	Node ans;ans.sz=a.sz+b.sz;
	ans.l_sum=add(a.l_sum,mul(pw2[a.sz],b.l_sum));
	ans.r_sum=add(b.r_sum,mul(pw2[b.sz],a.r_sum));
	ans.ans=add(mul(a.ans,pw2[b.sz]),mul(b.ans,pw2[a.sz]));
	ckadd(ans.ans,mul(a.l_sum,b.r_sum));
	return ans;
}
const int M=2*N;
Node node[M];
mt19937 rng(time(0));
int ls[M],rs[M],tsz,root,val[M],pri[M];
void pull(int c){
	if(ls[c])node[c]=node[ls[c]]+Node(val[c]);
	else node[c]=Node(val[c]);
	if(rs[c])node[c]=node[c]+node[rs[c]];
}
void rot_l(int &c){int a=rs[c],b=ls[a];rs[c]=b;ls[a]=c;pull(c);pull(a);c=a;}
void rot_r(int &c){int a=ls[c],b=rs[a];ls[c]=b;rs[a]=c;pull(c);pull(a);c=a;}
void Ins(int &c,int x){
	if(!c){c=++tsz;val[c]=x;pri[c]=rng();pull(c);return;}
	if(val[c]<x){
		Ins(rs[c],x);
		if(pri[rs[c]]>pri[c])rot_l(c);
		else pull(c);
	}else{
		Ins(ls[c],x);
		if(pri[ls[c]]>pri[c])rot_r(c);
		else pull(c);
	}
}
void Del(int &c,int x){
	if(val[c]==x){
		if(!ls[c])c=rs[c];
		else if(!rs[c])c=ls[c];
		else if(pri[ls[c]]>pri[rs[c]])rot_r(c),Del(rs[c],x),pull(c);
		else rot_l(c),Del(ls[c],x),pull(c);
	}else if(val[c]<x)Del(rs[c],x),pull(c);
	else Del(ls[c],x),pull(c);
}
/*void Split(int c,int &l,int &r,int x){
	if(!c){l=r=0;return;}
	if(val[c]<x){
		l=c;Split(rs[c],rs[l],r,x);
		pull(l);
	}else{
		r=c;Split(ls[c],l,ls[r],x);
		pull(r);
	}
}
void Split2(int c,int &l,int &r,int k){
	if(!c){l=r=0;return;}
	if(node[ls[c]].sz+1<=k){
		l=c;Split2(rs[c],rs[l],r,k-node[ls[c]].sz-1);
		pull(l);
	}else{
		r=c;Split2(ls[c],l,ls[r],k);
		pull(r);
	}
}
void Merge(int &c,int l,int r){
	if(!l||!r){c=l^r;return;}
	if(pri[l]>pri[r]){
		c=l;Merge(rs[c],rs[l],r);
		pull(c);
	}else{
		c=r;Merge(ls[c],l,ls[r]);
		pull(c);
	}
}
void Del(int &c){if(ls[c])Del(ls[c]),pull(c);else c=rs[c];}*/
int a[N];
int main(){
	int n=ri();
	pw2[0]=1;for(int i=1;i<=n;i++)pw2[i]=mul(pw2[i-1],2);
	for(int i=1;i<=n;i++){
		int x=ri();a[i]=x;

		//int x=rng()%1000000000+1;a[i]=x;

		/*tsz++;val[tsz]=x;pri[tsz]=rng();pull(tsz);
		int l,r;
		Split(root,l,r,x);
		Merge(root,l,tsz);
		Merge(root,root,r);*/
		Ins(root,x);
	}
	int ipw=inv(pw2[n]);
	printf("%i\n",mul(node[root].ans,ipw));
	for(int q=ri();q--;){
		int p,x;rd(p,x);

		//p=rng()%n+1;
		//x=rng()%1000000000+1;

		//int A,B;
		//Split(root,A,B,a[p]);
		//Split2(B,B,C,1);
		//Del(B);
		//Merge(root,A,B);
		//tsz++;val[tsz]=x;pri[tsz]=rng();pull(tsz);
		//int D,E;
		//Split(root,D,E,x);
		//Merge(root,D,tsz);
		//Merge(root,root,E);
		//printf("%i\n",mul(node[root].ans,ipw));
		Del(root,a[p]);
		Ins(root,x);
		a[p]=x;
		printf("%i\n",mul(node[root].ans,ipw));
	}
	//printf("%i\n",mer_cnt);
	return 0;
}