#include<bits/stdc++.h>

using namespace std;

const int mo=1000000007;
int n,a[35];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,s=0;
		scanf("%d",&x);
		for (;x%2==0;x/=2,++s);
		++a[s];
	}
	int ans=power(2,n)-1;
	int re=n-a[0];
	for (int i=1;i<=30;i++)
		if (a[i]!=0){
			ans=(ans+mo-power(2,re-1))%mo;
			re-=a[i];
		}
	cout<<ans<<endl;
}
/*
 iff
1. 
2. 
2
2
4
24
24
*/