#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n],mn=1e9;
    for(int i=0;i<n;i++)scanf("%i",&a[i]),mn=min(mn,a[i]);
    vector<int> v;
    for(int i=0;i<n;i++)if(a[i]==mn)v.push_back(i);
    int ans=n;
    for(int i=0;i<(int)v.size()-1;i++)ans=min(ans,v[i+1]-v[i]);
    printf("%i",ans);
    return 0;
}