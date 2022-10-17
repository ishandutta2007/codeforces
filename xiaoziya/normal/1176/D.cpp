#include<stdio.h>
const int maxn=400005,maxm=2750132;
int n,ps,as;
int a[maxn],c[maxm],p[maxm],mn[maxm],b[maxn],cnt[maxm],id[maxm];
void sieve(int n){
	c[1]=1;
	for(int i=2;i<=n;i++){
		if(c[i]==0)
			p[++ps]=i,mn[i]=1,id[i]=ps;
		for(int j=1;j<=ps&&i*p[j]<=n;j++){
			c[i*p[j]]=1,mn[i*p[j]]=p[j];
			if(i%p[j]==0)
				break;
		}
	}
}
int main(){
	scanf("%d",&n),sieve(2750131);
	for(int i=1;i<=n+n;i++)
		scanf("%d",&b[i]),cnt[b[i]]++;
	for(int i=2750131;i>=1;i--)
		while(cnt[i]){
			if(c[i]==0)
				cnt[id[i]]--,a[++as]=id[i];
			else cnt[i/mn[i]]--,a[++as]=i;
			cnt[i]--;
		}
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i],i==n? '\n':' ');
	return 0;
}