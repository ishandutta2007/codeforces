#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=505,P=1000000007;
int n,cnt[N];
int fpow(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;return res;}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x;scanf("%d",&x);
		if(~x)++cnt[x];
	}
	int tot=0;
	rep(i,1,n)if(cnt[i])(tot+=fpow(2,cnt[i])-1)%=P;
	printf("%d\n",(fpow(2,n-1)-1-tot+P)%P);
	return 0;
}