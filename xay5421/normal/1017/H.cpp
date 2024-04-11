// author: xay5421
// created: Wed Nov  3 19:04:58 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
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
const int N=100005;
int n,m,Q,a[N],w[N],cnt[N],ans[N],inv[N*2];
vector<tuple<int,int,int> >vec[N];
int nowk,res;
void ins(int x){
	res=mu(res,w[x]+nowk-cnt[x]),++cnt[x];
}
void del(int x){
	--cnt[x],res=mu(res,inv[w[x]+nowk-cnt[x]]);
}
void deal(vector<tuple<int,int,int> >&v,int k){
	nowk=k;
	vector<int>up(n+1);
	up[0]=1;
	rep(i,1,n){
		up[i]=mu(up[i-1],ad(i,mu(k,m)));
	}
	const int B=max(1.,n/sqrt(SZ(v)));
	sort(v.begin(),v.end(),[&](auto x,auto y){
		if(get<0>(x)/B!=get<0>(y)/B){
			return get<0>(x)<get<0>(y);
		}else{
			return get<0>(x)/B&1?get<1>(x)<get<1>(y):get<1>(x)>get<1>(y);
		}
	});
	memset(cnt,0,sizeof(cnt));
	int l=get<0>(v[0]),r=l-1;
	res=1;
	for(auto&x:v){
		int ql,qr,_;
		tie(ql,qr,_)=x;
		while(l>ql)ins(a[--l]);
		while(r<qr)ins(a[++r]);
		while(l<ql)del(a[l++]);
		while(r>qr)del(a[r--]);
		ans[_]=mu(res,up[n-(qr-ql+1)]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	rep(i,2,N*2-1)inv[i]=mu(P-P/i,inv[P%i]);
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,n)scanf("%d",&a[i]),++w[a[i]];
	rep(_,1,Q){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		vec[k].eb(l,r,_);
	}
	rep(i,0,100000)if(SZ(vec[i])){
		deal(vec[i],i);
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}