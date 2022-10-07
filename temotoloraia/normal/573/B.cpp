#include <bits/stdc++.h>
using namespace std;
long long int n,h[100009],i,j,k,l,ans; 
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
      cin>>h[i];
      h[i]=min(h[i],h[i-1]+1);
    }
    for(i=n;i>=1;i--)
    h[i]=min(h[i],h[i+1]+1);
    sort(h,h+n+1);
    cout<<h[n];
}