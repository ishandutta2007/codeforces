#include <bits/stdc++.h>
using namespace std;
bool Good(int*a,int n){
    for(int i=0;i<n-1;i++)if(a[i]>a[i+1])return 0;
    return 1;
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,x;scanf("%i %i",&n,&x);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        bool was=0;
        for(int i=0;i<=n;i++){
            if(Good(a,n)){
                printf("%i\n",i);
                was=1;
                break;
            }
            for(int j=0;j<n;j++){
                if(a[j]>x){
                    swap(a[j],x);
                    break;
                }
            }
        }
        if(!was)printf("-1\n");
    }
    return 0;
}