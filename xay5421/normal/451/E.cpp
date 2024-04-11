#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int P=1000000007;
int n,s,ans,inv[25],f[25];
int C(int a,int b){
	if(a-b<0)return 0;int res=1;a%=P;
	for(int i=1;i<=b;++i)res=res*(a-i+1)%P*inv[i]%P;
	return res;
}
signed main(){
	scanf("%I64d%I64d",&n,&s);
	inv[0]=inv[1]=1;
	rep(i,2,20)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	rep(i,1,n)scanf("%I64d",&f[i]);
	rep(i,0,(1<<n)-1){
		if(!i)ans=C(n+s-1,n-1);
		else{
			int sum=0,cnt=0;
			for(int j=0;j<n;++j)if(i>>j&1)++cnt,sum+=f[j+1];
			int tmp=C(n+s-sum-cnt-1,n-1);
			if(cnt&1)ans=(ans-tmp+P)%P;else ans=(ans+tmp)%P;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}