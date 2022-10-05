#include<bits/stdc++.h>
using namespace std;
bool c[1100];
int a[2100000];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n>m){
		cout<<0;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)ans=(1ll*ans*abs(a[i]-a[j]))%m;
	}
	cout<<ans;
	return 0;
}