#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int P=998244353;
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
int norm(LL x){
	x%=P;
	if(x<0)x+=P;
	return x;
}
const int N=105;
struct node{
	int n;
	LL L[N],R[N];
	vector<pair<LL,LL> >segs[65];
	void ask(int k1,LL k2,LL k3,LL k4,LL k5,int k6){
		if(k2>k5||k3<k4)return;
		if(!k6){
			segs[k1].eb(k2,k3);
		}
		if(k4<=k2&&k3<=k5){
			if(k6){
				segs[k1].eb(k2,k3);
			}
			return;
		}
		LL mid=(k2+k3)>>1;
		ask(k1-1,k2,mid,k4,k5,k6);
		ask(k1-1,mid+1,k3,k4,k5,k6);
	}
	void init(){
		scanf("%d",&n);
		rep(i,1,n)scanf("%lld%lld",&L[i],&R[i]);
	}
	void gen1(){
		fill(segs,segs+65,vector<pair<LL,LL> >{});
		rep(i,1,n){
			ask(60,0,(1LL<<60)-1,L[i],R[i],0);
		}
	}
	void gen2(){
		fill(segs,segs+65,vector<pair<LL,LL> >{});
		rep(i,1,n){
			ask(60,0,(1LL<<60)-1,L[i],R[i],1);
		}
	}
}A[2];
vector<pair<LL,LL> >glo;
void sol(node&a,node&b){
	a.gen1(),b.gen2();
	rep(i,0,64){
		for(auto&x:a.segs[i]){
			for(auto&y:b.segs[i]){
				glo.eb(x.first^y.first,x.first^y.second);
			}
		}
	}
}
int get_sum(int n){
	return 1LL*n*(n+1)/2%P;
}
int get_sum(LL l,LL r){
	return su(get_sum(norm(r)),get_sum(norm(l-1)));
}
int main(){
	A[0].init(),A[1].init();
	sol(A[0],A[1]);
	sol(A[1],A[0]);
	sort(glo.begin(),glo.end());
	LL maxr=-1;
	int ans=0;
	for(auto&x:glo){
		if(x.second>maxr){
			uad(ans,get_sum(max(maxr+1,x.first),x.second));
			maxr=x.second;
		}
	}
	printf("%d\n",ans);
	return 0;
}