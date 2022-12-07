#include<bits/stdc++.h>

using namespace std;

const int N=100005;
long long f[N],sf[N];
long long g[20][N];
void init(){
	for (int i=1;i<N;i++) f[i]=i;
	for (int i=1;i<N;i++)
		for (int j=i+i;j<N;j+=i)
			f[j]-=f[i];
	for (int i=1;i<N;i++) f[i]+=f[i-1];
}
long long c(int l,int r){
	long long sum=0;
	for (int i=l;i<=r;){
		int v=r/i,j=r/v; 
		sum+=1ll*(j-i+1)*f[v];
		i=j+1;
	}
	return sum;
}
void solve(long long *f,long long *g,int l,int r,int L,int R){
	if (l>r) return;
	int mid=(l+r)/2,pos=L;
	if (min(mid-1,R)>=L){
		long long tr=c(L+1,mid);
		for (int i=L;i<mid&&i<=R;i++){
			if (g[i]+tr<=f[mid]){
				f[mid]=g[i]+tr;
				pos=i;
			}
			tr-=::f[mid/(i+1)];
		}
	}
	solve(f,g,l,mid-1,L,pos);
	solve(f,g,mid+1,r,pos,R);
}
int main(){
	init();
	memset(g,30,sizeof(g));
	for (int i=1;i<N;i++) g[1][i]=1ll*i*(i+1)/2;
	for (int i=2;i<=17;i++) solve(g[i],g[i-1],i,N-1,i-1,N-1);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int k,n;
		scanf("%d%d",&n,&k);
		if (k>=18) printf("%d\n",n);
		else printf("%lld\n",g[k][n]);
	}
}