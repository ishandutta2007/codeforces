#include<cstdio>
#include<map>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
#define pp(x) __builtin_popcountll(x)
const int N=300005;
int n,P,k,ans,a[N];std::map<int,int>S;
int pow4(int a){return 1ll*a*a%P*a%P*a%P;} 
signed main(){
	scanf("%I64d%I64d%I64d",&n,&P,&k);
	rep(i,1,n)scanf("%I64d",&a[i]),a[i]%=P;
	for(int i=1;i<=n;++i){
		ans+=S[(-1ll*k*a[i]%P+pow4(a[i])+P)%P];
		++S[(pow4(a[i])-1ll*k*a[i]%P+P)%P];
	}
	printf("%I64d\n",ans);
	return 0;
}