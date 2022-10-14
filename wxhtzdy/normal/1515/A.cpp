#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,x;
        scanf("%i%i",&n,&x);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        bool ok=true;
        int s=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            if(s==x){
                if(i==n-1)ok=false;
                else swap(a[i],a[i+1]);
            }
        }
        if(!ok)printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<n;i++)printf("%i ",a[i]);
            printf("\n");
        }
    }
    return 0;
}