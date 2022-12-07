#include<bits/stdc++.h>
using namespace std;

int n,a[5005],b[5005];
long long ans,s;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) s+=1ll*a[i]*b[i];
	ans=s;
	for (int i=1;i<n;i++){
		long long ts=s;
		for (int j=i,k=i+1;j>=1&&k<=n;--j,++k){
			ts-=1ll*a[j]*b[j]+1ll*a[k]*b[k];
			ts+=1ll*a[j]*b[k]+1ll*a[k]*b[j];
			ans=max(ans,ts);
		}
	}
	for (int i=2;i<n;i++){
		long long ts=s;
		for (int j=i-1,k=i+1;j>=1&&k<=n;--j,++k){
			ts-=1ll*a[j]*b[j]+1ll*a[k]*b[k];
			ts+=1ll*a[j]*b[k]+1ll*a[k]*b[j];
			ans=max(ans,ts);
		}
	}
	cout<<ans<<endl;
	
	
}