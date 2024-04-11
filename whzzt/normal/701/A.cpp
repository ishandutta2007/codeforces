#include<bits/stdc++.h>
using namespace std;
int n,a[105],s;bool vis[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	s/=n>>1;
	for(int i=1;i<=n;i++)if(!vis[i]){
		for(int j=i+1;j<=n;j++)if(!vis[j]&&a[i]+a[j]==s){
			vis[i]=vis[j]=true;
			printf("%d %d\n",i,j);
			break;
		}
	}
}