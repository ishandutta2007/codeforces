#include<cstdio>
int n,a[300010],mp[15000010],cnt[15000010];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	for(int i=2;i<=15000000;i++)if(!mp[i])
		for(int j=i;j<=15000000;j+=i)if(!mp[j])mp[j]=i;
	scanf("%d",&n);
	int g=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		g=gcd(g,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i]/=g;
		for(int x=a[i];x>1;){
			int p=mp[x];
			while(x%p==0)x/=p;
			cnt[p]++;
		}
	}
	int ans=n;
	for(int i=2;i<=15000000;i++)if(n-cnt[i]<ans)ans=n-cnt[i];
	if(ans==n)puts("-1");
	else printf("%d\n",ans);
}