#include<bits/stdc++.h>
using namespace std;
int ca[110000];
int da[110000],cb[110000],x[110000];
int vis[110000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>ca[i];
		for(int i=1;i<=n;i++)cin>>cb[i];
		for(int i=1;i<=n;i++)da[ca[i]]=i;
		for(int i=1;i<=n;i++)x[i]=cb[da[i]];
		for(int i=1;i<=n;i++)vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				int j=1;
				for(int k=x[i];k!=i;k=x[k]){
					vis[k]=1;
					j++;
				}
				cnt+=j/2;
			}
		}
		cout<<2ll*cnt*(n-cnt)<<endl;
	}
	return 0;
}