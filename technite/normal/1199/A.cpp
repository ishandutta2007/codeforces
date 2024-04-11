#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, x, y, j=0;
    cin>>n>>x>>y;
    int a[n];
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++){
        if(a[i]<a[j]) j=i;
        if(i-j==y) break;
    }
    cout<<j+1;
}