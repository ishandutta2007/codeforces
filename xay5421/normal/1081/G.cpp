#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,K,P,I,ans,inv[N],H[N],len[2],cnt[2];
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
void sol(int k1,int k2,int k3){
	if(k1>=K||k2==k3){
		int x=0;
		if(len[x]&&len[x]!=k3-k2+1)++x;
		len[x]=k3-k2+1;
		++cnt[x];
		ans=ad(ans,mu(mu(k3-k2+1,k3-k2+1-1),mu(I,I)));
		return;
	}
	int mid=(k2+k3)>>1;
	sol(k1+1,k2,mid);
	sol(k1+1,mid+1,k3);
}
int calc(int x,int y){
	if(!x||!y)return 0;
	int res=mu(mu(x,y),I);
	rep(i,1,x){
		res=su(res,su(H[i+y],H[i]));
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&K,&P);
	I=po(2,P-2);
	inv[0]=inv[1]=1;
	rep(i,2,N-1)inv[i]=mu(P-P/i,inv[P%i]);
	rep(i,1,N-1)H[i]=ad(H[i-1],inv[i]);
	sol(1,1,n);
	auto C2=[&](int x){return mu(mu(x,x-1),I);};
	ans=ad(ans,mu(C2(cnt[0]),calc(len[0],len[0])));
	ans=ad(ans,mu(C2(cnt[1]),calc(len[1],len[1])));
	ans=ad(ans,mu(mu(cnt[0],cnt[1]),calc(len[0],len[1])));
	printf("%d\n",ans);
	return 0;
}