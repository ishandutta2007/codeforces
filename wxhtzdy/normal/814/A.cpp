#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    int a[n],b[k];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<k;i++)scanf("%i",&b[i]);
    sort(b,b+k);
    reverse(b,b+k);
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)a[i]=b[j],j++;
    }
    bool ok=0;
    for(int i=1;i<n;i++)if(a[i]<a[i-1])ok=1;
    if(ok)printf("Yes");
    else printf("No");
}