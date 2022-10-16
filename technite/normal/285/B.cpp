#include <bits/stdc++.h>
using namespace std;
int s,n,op,t,i,a[100005];
int main(){
ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s>>t;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(s==t)cout<<0;
	else{
		for(i=1;i<=n and s!=t;i++){
			s=a[s];	
			if(s==t)cout<<i;
		}
		if(s!=t) cout<<-1;
	
	
	
	
	}
 
}