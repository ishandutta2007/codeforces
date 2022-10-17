#include<stdio.h>
const int maxn=200005,maxk=20;
int n,m,tot,q;
int a[maxn],f[maxn][maxk],sum[maxn],c[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[a[i]]++;
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+c[i];
	for(int t=1;t<=19;t++)
		for(int i=1;i+(1<<t)-1<=m;i++){//[i,i+(1<<t)-1]
			f[i][t]=f[i][t-1]^f[i+(1<<(t-1))][t-1];
			if((sum[i+(1<<t)-1]-sum[i+(1<<(t-1))-1])&1)
				f[i][t]^=(1<<(t-1));
		}
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		int ans=0,S=0;
		for(int t=20;t>=0;t--)
			if(l+(1<<t)-1<=r){
				ans^=f[l][t];
				if((sum[l+(1<<t)-1]-sum[l-1])&1)
					ans^=S;
				l+=(1<<t),S+=(1<<t);
			}
		putchar(ans==0? 'B':'A');
	}
	return 0;
}