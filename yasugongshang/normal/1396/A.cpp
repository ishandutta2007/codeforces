#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cout<<"1 1"<<endl;
    cout<<-a[1]<<endl;
    a[1] = 0;
    if(n==1){
		puts("1 1\n0\n1 1\n0");
		return 0; 
	}
    cout<<"2 "<<n<<endl;
    for(int i=2;i<=n;++i){
        cout<<1ll*a[i]*(n-1)<<" ";
        a[i] = a[i]*n;
    }
    cout<<endl;
    cout<<"1 "<<n<<endl;
    for(int i=1;i<=n;++i){
        cout<<-a[i]<<" ";
    }
    
}