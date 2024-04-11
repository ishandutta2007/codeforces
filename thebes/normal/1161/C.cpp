
#include <bits/stdc++.h>
using namespace std;

int a[55], n, i, x;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<n-((n/2)-1);i++){
        if(a[i]!=a[i+1]) x=1;
    }
    printf("%s\n",!x?"Bob":"Alice");
    return 0;
}