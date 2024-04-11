#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        long long bal=0,mn=0;
        for(int i=0;i<n;i++)bal+=a[i],mn=min(mn,bal);
        printf("%lld\n",abs(mn));
    }
    return 0;
}