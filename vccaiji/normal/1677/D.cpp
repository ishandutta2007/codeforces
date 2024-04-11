#include<bits/stdc++.h>
using namespace std;
int v[1100000];
const int p=998244353;
int main(){
	int _;
	cin>>_;
	while(_--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		int ans=1;
		bool r=1;
		for(int i=n-k+1;i<=n;i++)if(v[i]>0){
			cout<<0<<endl;
			r=0;
			break;
		}
		if(!r)continue;
		for(int i=1;i<=k;i++)ans=(1ll*ans*i)%p;
		for(int i=1;i<=n-k;i++){
			if(v[i]==0)ans=(1ll*ans*(k+1))%p;
			if(v[i]==-1)ans=(1ll*ans*(k+i))%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}