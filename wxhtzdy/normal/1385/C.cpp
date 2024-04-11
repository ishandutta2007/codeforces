#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int pre[n],pos[n];
		for(int i=0;i<n;i++){
			if(i==0||a[i]>a[i-1])pre[i]=i;
			else pre[i]=pre[i-1];
		}
		for(int i=n-1;i>=0;i--){
			if(i==n-1||a[i]>a[i+1])pos[i]=i;
			else pos[i]=pos[i+1];
		}
		int ans=0,bio=0;
		for(int i=0;i<n;i++){
			if(pos[i]>=pre[n-1]){ans=i;break;}
		}
		cout<<ans<<endl;
	}
}