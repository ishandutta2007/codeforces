#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MOD=1e9+7;
int f[5000005],prime[5000005],cnt;
bool flag[5000005];
void pre(){
	for(int i=2;i*i<=5000000;i++){
		if(!flag[i]){
			prime[cnt++]=i;
			for(int j=i*i;j<=5000000;j+=i){
				flag[j]=true;
			}
		}
	}
}
void go(){
	for(int i=2;i<=5000000;i++){
		if(!flag[i])	f[i]=(i*(i-1)/2)%MOD;
		else{
			int x;
			for(int k=0;k<cnt;k++){
				if(i%prime[k]==0){
					x=prime[k];
					break;
				}
			}
			f[i]=(i/x*f[x]%MOD+f[i/x]%MOD)%MOD;
		}
	}
}
int t,l,r,s[5000005];
void getfac(){
	s[0]=1;
	for(int i=1;i<=5000000;i++)	s[i]=s[i-1]*t%MOD;
}
signed main(){
	cin>>t>>l>>r;
	pre();go();
	int ans=0ull;
	getfac();
	for(int i=l;i<=r;i++)	ans=(ans+(s[i-l]*f[i])%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}