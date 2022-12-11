#include<bits/stdc++.h>
using namespace std;
const int N=57;
int t,n,tot,a[N];
int main(){
	cin>>t;
	while(t--){
        cin>>n;
        tot=0;
        for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i]-1;
        if(tot&1) puts("errorgorn");
        else puts("maomao90");
    }
	return 0;
}