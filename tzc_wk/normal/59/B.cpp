#include <bits/stdc++.h>
using namespace std;
int n,a[101],p=0,ans=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2) p++; 
    }
    if(p==0)	cout<<0<<endl,exit(0);
    if(p%2){
        for(int i=1;i<=n;i++) ans+=a[i];
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) if(a[i]%2){a[i]=0;break;}
    for(int i=1;i<=n;i++) ans+=a[i];
    cout<<ans<<endl;
    return 0;
}