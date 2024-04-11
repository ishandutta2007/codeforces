#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define LL long long
const int N=1000005;
int n,ans,p[N];bool ban[N],pd[N];LL a[N];
int brand(){return(rand()<<16)+(rand()<<1)+(rand()&1);}
void init(){
	int i,j;
	ban[0]=ban[1]=1;
	for(i=2;i<N;++i){
		if(!ban[i])p[++*p]=i;
		for(j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
void sol(LL x){
	if(x<N&&pd[x])return;
	if(x<N)pd[x]=1;
	int i;LL res=0;
	for(i=1;i<=n;++i){
		if(a[i]<=x)res+=x-a[i];else res+=std::min(a[i]%x,x-a[i]%x); 
		if(res>=ans)return;
	}
	ans=res;
}
void doo(LL n){
	int i;
	for(i=1;i<=*p&&p[i]<=n;++i)if(n%p[i]==0){
		do n/=p[i];while(n%p[i]==0);
		sol(p[i]);
	}
	if(n>1)sol(n);
}
int main(){
    srand(time(0)^(unsigned long long)(new char));
	int i;
	init();
	scanf("%d",&n),ans=n;
	for(i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(i=1;i<=30;++i){
		LL x=a[brand()%n+1];
		doo(x-1),doo(x),doo(x+1);
	}
	printf("%d\n",ans);
	return 0;
}