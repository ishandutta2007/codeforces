#include<bits/stdc++.h>
using namespace std;
int a[110000];
const int B=200;
int cnt[1010000];
int s[110000];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=-B;i<=B;i++){
		for(int j=1;j<=n;j++) s[j]=a[j]-i*j;
		sort(s+1,s+n+1);
		for(int j=1,k=1;j<=n;j++,k++){
			if((j==n)||(s[j+1]!=s[j])){
				ans=max(ans,k);
				k=0;
			}
		}
	}
	int C=510;
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-C);j<=i-1;j++) if((a[j]-a[i])%(i-j)==0) cnt[110000+(a[j]-a[i])/(i-j)]++;
		for(int j=max(1,i-C);j<=i-1;j++) if((a[j]-a[i])%(i-j)==0) ans=max(ans,cnt[110000+(a[j]-a[i])/(i-j)]+1);
		for(int j=max(1,i-C);j<=i-1;j++) cnt[110000+(a[j]-a[i])/(i-j)]=0;
	}
	cout<<n-ans;
	return 0;
}