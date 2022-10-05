#include<bits/stdc++.h>
using namespace std;
int n,x;
long long a[110000];
long long s[110000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)a[i]+=a[i-1]; 
		cin>>x;
		for(int i=0;i<=n;i++)s[i]=a[i]-1ll*i*x;
		int num=0;
		long long maxx=-10000000000000000ll;
		for(int i=1;i<=n;i++){
			if(s[i]<maxx){
				maxx=-10000000000000000ll;
				continue;
			}
			maxx=max(maxx,s[i-1]);
			num++;
		}
		cout<<num<<endl;
	} 
	return 0;
}