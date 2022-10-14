#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    vector<pair<int,int>> v;
    long long ans=0;
    for(int i=0;i<n;i++)ans+=abs(a[i]-(i+1));
    printf("%lld",ans);
    return 0;
}