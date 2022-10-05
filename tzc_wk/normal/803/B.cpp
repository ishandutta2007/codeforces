#include <bits/stdc++.h>
using namespace std;
int n,a[200005],last,ans[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	memset(ans,0x3f3f3f3f,sizeof(ans));
	last=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(a[i]==0)	last=i;
		ans[i]=min(ans[i],abs(i-last));
	}
	last=0x3f3f3f3f;
	for(int i=n;i>=1;i--){
		if(a[i]==0)	last=i;
		ans[i]=min(ans[i],abs(i-last));
	}
	for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";
	return 0;
}