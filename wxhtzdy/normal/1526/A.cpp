#include <bits/stdc++.h>
using namespace std;

const int N=55;

int a[N];

void solve(){
    int n;scanf("%i",&n);
    for(int i=1;i<=2*n;i++)scanf("%i",&a[i]);
    sort(a+1,a+2*n+1);
    for(int i=1;i<=n;i++)printf("%i %i ",a[i],a[i+n]);
    printf("\n");
}

int main(){
    int t;scanf("%i",&t);
    while(t--)
        solve();
    return 0;
}