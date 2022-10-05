#include<bits/stdc++.h>
using namespace std;
int n,a,b,k; 
const int p=1000000009;
int qow(int aa,int m){
	int ans=1;
	for(;m;m>>=1){
		if(m&1)ans=1ll*ans*aa%p;
		aa=1ll*aa*aa%p;
	}
	return ans;
}
int inverse(int a){
	return qow(a,p-2);
}
char s[110000];
int pa[110000],pb[110000];
int main(){
	cin>>n>>a>>b>>k;
	pa[0]=1;
	for(int i=1;i<=k;i++)pa[i]=1ll*pa[i-1]*a%p;
	pb[0]=1;
	for(int i=1;i<=k;i++)pb[i]=1ll*pb[i-1]*b%p;
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<k;i++){
		if(s[i]=='+')ans=(ans+1ll*pa[k-1-i]*pb[i])%p;
		else ans=(ans+1ll*(p-pa[k-1-i])*pb[i])%p;
	}
	int n1=(n+1)/k;
	int a1=qow(a,k),b1=qow(b,k);
	if(a1==b1)ans=1ll*ans*n1%p*qow(a1,n1-1)%p;
	else ans=1ll*ans*(p+qow(a1,n1)-qow(b1,n1))%p*inverse((p+a1-b1)%p)%p;
	cout<<ans;
	return 0;
}