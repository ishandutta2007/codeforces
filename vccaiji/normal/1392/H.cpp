#include<bits/stdc++.h>
using namespace std;
int p=998244353;
int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1) ans=((long long)ans*a)%p;
		a=((long long)a*a)%p;
	}
	return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+qow(i,p-2))%p;
    ans=((long long)ans*m)%p;
    ans=(ans+1)%p;
	ans=((long long)ans*(m+n+1))%p;
	ans=((long long)ans*qow(m+1,p-2))%p;
	cout<<ans;
	return 0;
}