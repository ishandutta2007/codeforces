// author: xay5421
// created: Fri Apr 23 11:24:30 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=300005;
int n,la,lb,da,db,wa,wb,pw[N],s2[N],fac[N*2],inv[N*2],ifac[N*2],p[N],miu[N],co[N],ans;
bool ban[N];
char A[N],B[N];
void sieve(){
	ban[0]=ban[1]=1,miu[1]=1;
	rep(i,2,N-1){
		if(!ban[i])p[++*p]=i,miu[i]=P-1;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
			miu[i*p[j]]=su(0,miu[i]);
		}
	}
	rep(i,1,N-1)for(int j=i,k=1;j<N;j+=i,++k){
		uad(co[j],mu(pw[i],miu[k]));
	}
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
int calc(int n){
	int res=0;
	rep(i,1,n)uad(res,mu(n/i,n/i,co[i]));
	return res;
}
void deal(int all){
	int tt=la==lb;
	if(tt){
		rep(i,1,la){
			if(A[i]=='?'||B[i]=='?'){
				if(A[i]=='?'&&B[i]=='?'){
					tt=ad(tt,tt);
				}
			}else if(A[i]!=B[i]){
				tt=0;
				break;
			}
		}
	}
	usu(all,tt);
	if(tt)uad(ans,mu(tt,mu(s2[n],s2[n])));
	if(all){
		uad(ans,mu(all,calc(n)));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N*2-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	pw[0]=1;
	rep(i,1,N-1)pw[i]=ad(pw[i-1],pw[i-1]);
	rep(i,1,N-1)s2[i]=ad(s2[i-1],pw[i]);
	sieve();
	//rep(i,1,N-1)s2[i]=mu(s2[i],s2[i]);
	scanf("%s%s%d",A+1,B+1,&n);
	la=strlen(A+1),lb=strlen(B+1);
	rep(i,1,la)wa+=A[i]=='?',da+=A[i]=='A',db+=A[i]=='B';
	rep(i,1,lb)wb+=B[i]=='?',da-=B[i]=='A',db-=B[i]=='B';
	rep(i,-wb,wa){
		int j=wa-wb-i;
		int da_=da+i,db_=db+j;
		if(da_>0&&db_>0)continue;
		if(da_<0&&db_<0)continue;
		if((da_==0||db_==0)&&da_+db_!=0)continue;
		if(da_==0&&db_==0){
			deal(C(wa+wb,wa-i));
		}else{
			int p=abs(db_),q=abs(da_);
			{
				int t=__gcd(p,q);
				p/=t,q/=t;
			}
			uad(ans,mu(s2[n/max(p,q)],C(wa+wb,wa-i)));
		}
	}
	printf("%d\n",ans);
	return 0;
}