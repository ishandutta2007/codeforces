#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int a[n],b[m];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<m;i++)scanf("%i",&b[i]);
    sort(a,a+n);sort(b,b+m);
    int mn=10;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(a[i]==b[j])mn=min(mn,a[i]);
    }
    if(mn!=10){
        printf("%i",mn);
    }else{
        printf("%i%i",min(a[0],b[0]),max(a[0],b[0]));
    }
    return 0;
}