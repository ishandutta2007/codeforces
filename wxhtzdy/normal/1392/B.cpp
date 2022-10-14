#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        long long k;scanf("%lld",&k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        if(k&1){
            int mx=-1e9;
            for(int i=0;i<n;i++)mx=max(mx,a[i]);
            for(int i=0;i<n;i++)printf("%i ",mx-a[i]);
            printf("\n");
        }else{
            int mx=-1e9;
            for(int i=0;i<n;i++)mx=max(mx,a[i]);
            for(int i=0;i<n;i++)a[i]=mx-a[i];
            mx=-1e9;
            for(int i=0;i<n;i++)mx=max(mx,a[i]);
            for(int i=0;i<n;i++)printf("%i ",mx-a[i]);
            printf("\n");
        }
    }
    return 0;
}