#include<iostream>
#include<vector>
#include<queue>
using namespace std;
main(){
long long a[200010],n,b[100010];
cin>>n;
for(int i=0;i<n/2;i++)cin>>b[i];
a[0]=0;a[n-1]=b[0];
for(int i=1;i<n/2;i++){
    a[n-i-1]=b[i]-a[i-1];
    a[i]=a[i-1];
    if(a[n-i-1]>a[n-i]){a[i]+=(a[n-i-1]-a[n-i]);a[n-i-1]=a[n-i];}
    
}
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}