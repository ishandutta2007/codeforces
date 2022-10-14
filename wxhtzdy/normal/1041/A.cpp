#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n-1;i++)ans+=a[i+1]-a[i]-1;
    printf("%i",ans);
}