#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int P=998244353;
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
const int N=35*35,B=1000000,iB=fpow(B,P-2);
int n,a[N],cut[N],fac[N],inv[N],ifac[N];
vector<int>pos,jia,zhen;
vector<int>A[N];
vector<int>pji(vector<int>a){
	vector<int>b{0};
	for(int i=0;i<SZ(a);++i)b.PB(1LL*a[i]*fpow(i+1,P-2)%P);
	while(SZ(b)>1&&b.back()==0)b.pop_back();
	return b;
}
int fun(vector<int>a,int x){
	int res=0,bs=1;
	for(int i=0;i<SZ(a);++i){
		if(i)bs=1LL*bs*x%P;
		(res+=1LL*a[i]*bs%P)%=P;
	}
	return res;
}
vector<int>psub(vector<int>a,vector<int>b){
	a.resize(max(SZ(a),SZ(b)));
	for(int i=0;i<SZ(b);++i)a[i]=(a[i]+P-b[i])%P;
	return a;
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
vector<int>shift(vector<int>a,int k){ // b(x)=a(x+k)
	vector<int>b(SZ(a));
	rep(i,0,SZ(a)-1){
		rep(j,0,i){
			(b[j]+=1LL*a[i]*fpow(k,i-j)%P*C(i,j)%P)%=P;
		}
	}
	return b;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d",&n);
	rep(i,0,n-1){
		double k1;
		scanf("%lf",&k1);
		a[i]=(int)(k1*B+.5);
		pos.PB(a[i]%B);
	}
	pos.PB(0);
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	jia.assign(SZ(pos)*n+1,0);
	zhen.assign(SZ(pos)*n+1,0);
	rep(i,0,SZ(pos)*n)jia[i]=i/SZ(pos)*B+pos[i%SZ(pos)],zhen[i]=1LL*jia[i]*iB%P;
	rep(i,0,n-1)cut[i]=lower_bound(jia.begin(),jia.end(),a[i])-jia.begin();
	rep(i,0,SZ(pos)*n)A[i]={i<min(SZ(pos),cut[0])?1:0};
	rep(_,1,n-1){
		rep(i,0,SZ(pos)*n)A[i]=pji(A[i]);
		per(i,SZ(pos)*n-1,0){
			A[i][0]=(A[i][0]+P-fun(A[i],zhen[i]))%P;
			for(int j=i-1;j>=i-SZ(pos)&&j>=0;--j){
				A[i][0]=(A[i][0]+fun(A[j],zhen[j+1]))%P;
				if(j>i-SZ(pos)){
					A[i][0]=(A[i][0]+P-fun(A[j],zhen[j]))%P;
				}else{
					A[i]=psub(A[i],shift(A[j],P-1));
				}
			}
		}
		rep(i,cut[_],SZ(pos)*n)A[i]={0};
	}
	int ans=0;
	rep(i,0,SZ(pos)*n-1){
		ans=((LL)ans+fun(pji(A[i]),zhen[i+1])+P-fun(pji(A[i]),zhen[i]))%P;
	}
	printf("%d\n",ans);
	return 0;
}