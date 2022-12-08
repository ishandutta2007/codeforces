#include<cstring>
#include<cstdio>
#define N 1000000
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int p[N+6],mu[N+6],phi[N+6],cnt;
bool is[N+6];
void sieve(int n) {
	mu[1]=1,phi[1]=1,is[1]=0;
	rep(i,2,n) {
		if (is[i]) p[++cnt]=i,mu[i]=-1,phi[i]=i-1;
		for (int j=1;j<=cnt&&p[j]*i<=N;++j) {
			is[i*p[j]]=0;
			if (i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*(p[j]-1);
			else {
				mu[i*p[j]]=0;phi[i*p[j]]=phi[i]*p[j];is[i*p[j]]=0;
				break;
			}
		}
	}
}
int main() {
	rep(i,1,N)is[i]=1;sieve(N);int n;
	scanf("%d",&n);rep(i,2,n)if(!is[i]&&!is[n-i]) return printf("%d %d\n",i,n-i),0;
	return 0;
}