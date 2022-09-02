#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005;
int K,n,m,pos[N*4],pos0;
struct node{
	int l,r;
	bool operator<(const node&rhs)const{
		return l<rhs.l;
	}
}A[N],B[N];
vector<int>limA[N*4],limB[N*4];
struct segTree{
	int f[N*4],R,sum;
	int sums(){
		return sum;
	}
	void add(int k4,int k5){
		uad(f[k4],k5);
		R=min(R,k4);
		uad(sum,k5);
	}
	void set0(int k5){
		while(R<=k5){
			usu(sum,f[R]);
			f[R]=0;
			R+=1;
		}
	}
}F,G;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&K,&n,&m);
	if(n==0&&m==0){
		printf("%d\n",po(2,K));
		return 0;
	}
	rep(i,1,n)scanf("%d%d",&A[i].l,&A[i].r),pos[++pos0]=A[i].l,pos[++pos0]=A[i].r;
	rep(i,1,m)scanf("%d%d",&B[i].l,&B[i].r),pos[++pos0]=B[i].l,pos[++pos0]=B[i].r;
	sort(pos+1,pos+pos0+1);
	pos0=unique(pos+1,pos+pos0+1)-pos-1;
	rep(i,1,n){
		A[i].l=lower_bound(pos+1,pos+pos0+1,A[i].l)-pos;
		A[i].r=lower_bound(pos+1,pos+pos0+1,A[i].r)-pos;
		limA[A[i].r].pb(A[i].l);
	}
	rep(i,1,m){
		B[i].l=lower_bound(pos+1,pos+pos0+1,B[i].l)-pos;
		B[i].r=lower_bound(pos+1,pos+pos0+1,B[i].r)-pos;
		limB[B[i].r].pb(B[i].l);
	}
	F.add(0,1);
	G.add(0,1);
	F.add(0,pos[1]-1==0?0:su(po(2,pos[1]-1),1));
	G.add(0,pos[1]-1==0?0:su(po(2,pos[1]-1),1));
	{
		int r0=-1,r1=-1;
		if(!limA[1].empty()){
			r0=*max_element(limA[1].begin(),limA[1].end());
		}
		if(!limB[1].empty()){
			r1=*max_element(limB[1].begin(),limB[1].end());
		}
		if(r0!=-1){
			G.set0(r0-1);
		}
		if(r1!=-1){
			F.set0(r1-1);
		}
	}
	rep(i,1,pos0-1){ // (pos[i],pos[i+1]]
		int r0=-1,r1=-1;
		if(!limA[i+1].empty()){
			r0=*max_element(limA[i+1].begin(),limA[i+1].end());
		}
		if(!limB[i+1].empty()){
			r1=*max_element(limB[i+1].begin(),limB[i+1].end());
		}
		int coef=pos[i+1]-pos[i]==1?0:su(po(2,pos[i+1]-pos[i]-1),1);
		int sumF=F.sums();
		int sumG=G.sums();
		F.add(i,mu(coef,ad(sumF,sumG)));
		G.add(i,mu(coef,ad(sumF,sumG)));
		F.add(i,sumG);
		G.add(i,sumF);
		if(r0!=-1){
			G.set0(r0-1);
		}
		if(r1!=-1){
			F.set0(r1-1);
		}
	}
	printf("%d\n",mu(ad(F.sums(),G.sums()),po(2,K-pos[pos0])));
	return 0;
}