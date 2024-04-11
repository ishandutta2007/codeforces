#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;scanf("%i %i",&n,&s);
    int a[n],b[n],mn=0,mx=0;
    for(int i=0;i<n;i++)scanf("%i %i",&a[i],&b[i]),mn+=a[i],mx+=b[i];
    if(mn>s||mx<s)return 0*printf("NO");
    printf("YES\n");
    int need=s-mn;
    for(int i=0;i<n;i++){
        printf("%i ",a[i]+min(b[i]-a[i],need));
        need-=min(b[i]-a[i],need);
    }
    return 0;
}