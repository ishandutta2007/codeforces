#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=10000005,P=1e9+7;
int a[N];
int p[N/10],mu[N],pw[N];bool ban[N];
void make_p(){
	ban[0]=ban[1]=1,mu[1]=-1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
			mu[i]=1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
			mu[i*p[j]]=-mu[i];
		}
	}
}
int main(){
	make_p();
	pw[0]=1;
	rep(i,1,N-1)(pw[i]=pw[i-1]+pw[i-1])>=P&&(pw[i]-=P);
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		++a[x];
	}
	int ans=0;
	rep(i,2,N-1)if(mu[i]){
		int f=0;
		for(int j=i;j<N;j+=i)f+=a[j];
		(ans+=1LL*mu[i]*(n-f)*(pw[f]-1)%P)%=P;
	}
	if(ans<0)ans+=P;
	printf("%d\n",ans);
	return 0;
}