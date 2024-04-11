#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
const int mod=998244353;

ll ans,f[N];
int n,arr[N],rk[N],id[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		char c;cin>>c;
		if(c=='+')cin>>arr[i];
	}
	iota(rk,rk+N,0);
	sort(rk,rk+n,[](int a,int b){return arr[a]<arr[b];});
	for(int i=0;i<n;i++)id[rk[i]]=i;
	for(int i=0;i<n;i++)if(arr[i]){
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int j=0;j<i;j++){
			if(!arr[j]){
				(f[0]*=2)%=mod;
				for(int k=1;k<=n;k++){
					(f[k-1]+=f[k])%=mod;
				}
			}
			else if(id[j]<id[i]){
				for(int k=n;~k;k--){
					(f[k+1]+=f[k])%=mod;
				}
			}
			else{
				for(int k=0;k<=n;k++){
					(f[k]*=2)%=mod;
				}
			}
		}
		for(int j=i+1;j<n;j++){
			if(!arr[j]){
				for(int k=1;k<=n;k++){
					(f[k-1]+=f[k])%=mod;
				}
			}
			else if(id[j]<id[i]){
				for(int k=n;~k;k--){
					(f[k+1]+=f[k])%=mod;
				}
			}
			else{
				for(int k=0;k<=n;k++){
					(f[k]*=2)%=mod;
				}
			}
		}
		for(int j=0;j<=n;j++)(ans+=arr[i]*f[j]%mod)%=mod;
	}
	cout<<ans;
}