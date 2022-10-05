#include <bits/stdc++.h>
using namespace std;
int n,k,a[100001],t[100001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)	scanf("%d",a+i);
	for(int i=0;i<n;i++)	scanf("%d",t+i);
	int ans=0,tmp=0,pt=0;
	for(int i=0;i<k;i++)	tmp+=a[i];
	for(int i=k;i<n;i++)	tmp+=(t[i]==0)?0:a[i];
	while(pt<=n-k){
		ans=max(ans,tmp);
		tmp-=(t[pt]==0)?a[pt]:0;
		tmp+=(t[pt+k]==0)?a[pt+k]:0;
		pt++;
	}
	ans=max(ans,tmp);
	printf("%d\n",ans);
}