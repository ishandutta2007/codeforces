#include<stdio.h>
const int maxn=600005,maxk=21;
int n,m,k,l,r;
long long ans;
int a[maxn],jump[maxn][maxk],stk[maxn],mn[maxn];
long long val[maxn][maxk];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n+k;i++)
		for(int j=0;j<=20;j++)
			jump[i][j]=n+k;
	l=1,r=0;
	for(int i=n;i>=1;i--){
		while(l<=r&&a[stk[r]]>=a[i])
			r--;
		stk[++r]=i;
		while(l<=r&&stk[l]>i+k)
			l++;
		mn[i]=a[stk[l]];
	}
	for(int i=n-k;i>=1;i--){
		jump[i][0]=i+k;
		if(mn[jump[i][0]]>=mn[i]){
			int x=jump[i][0];
			for(int j=20;j>=0;j--)
				if(mn[jump[x][j]]>=mn[i])
					x=jump[x][j];
			jump[i][0]=jump[x][0];
		}
		val[i][0]=1ll*mn[i]*((jump[i][0]-i)/k);
		for(int j=1;j<=20;j++)
			jump[i][j]=jump[jump[i][j-1]][j-1],val[i][j]=val[i][j-1]+val[jump[i][j-1]][j-1];
	}
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		long long ans=a[l];
		for(int j=20;j>=0;j--)
			if(jump[l][j]<=r)
				ans+=val[l][j],l=jump[l][j];
		ans+=1ll*mn[l]*((r-l)/k);
		printf("%lld\n",ans);
	}
	return 0;
}