#include <bits/stdc++.h>
using namespace std;
int n,d,ans=0;
int main(){
	cin>>n>>d;
	int a[1100];
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		if(i!=j&&abs(a[i]-a[j])<=d) ans++;
    cout<<ans<<endl;
    return 0;
}