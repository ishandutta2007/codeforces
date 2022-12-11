#include<bits/stdc++.h>
using namespace std;
int t,n,k,vis[1<<17];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++) vis[i]=0;
		if(k==n-1){
			if(n==4){cout<<-1<<endl;continue;}
			cout<<1<<" "<<3<<endl;
			cout<<n-2<<" "<<n-1<<endl;
			cout<<n-4<<" "<<0<<endl;
			vis[1]=vis[3]=vis[n-2]=vis[n-1]=vis[n-4]=vis[0]=1;
		}
		else if(k){
			cout<<n-1<<" "<<k<<endl;
			cout<<0<<" "<<n-1-k<<endl;
			vis[n-1]=vis[k]=vis[0]=vis[n-1-k]=1;
		}
		for(int i=0;i<n;i++){
			if(vis[i])continue;
			cout<<i<<" "<<n-1-i<<endl;
			vis[i]=vis[n-1-i]=1;
		}
	}
	return 0;
}