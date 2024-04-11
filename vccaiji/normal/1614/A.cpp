#include<bits/stdc++.h>
using namespace std;
int _;
int a[1120];
int tot=0;
int b[1120];
int main(){
	scanf("%d",&_);
	while(_--){
		int n,l,r,k;
		scanf("%d%d%d%d",&n,&l,&r,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		tot=0;
		for(int i=1;i<=n;i++)if((a[i]>=l)&&(a[i]<=r))b[++tot]=a[i];
		sort(b+1,b+tot+1);
		int ans=0;
		for(int i=1;i<=tot;i++){
			if(k<b[i])break;
			ans++;
			k-=b[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}