#include <bits/stdc++.h>
using namespace std;
const int N=150;
int n,a[N];
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    int ans=0;
    while(true){
        sort(a+2,a+n+1);
        if(a[1]>a[n])break;
        a[1]++;
        a[n]--;
        ans++;
    }
    printf("%i",ans);
    return 0;
}