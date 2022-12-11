#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int pd1=0,pd2=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&a[i]);
            if(a[i]==0)pd1=1;
            if(a[i]==1)pd2=1;
        }
        if(pd1&&pd2)puts("NO");
        else{
            if(pd2){
                stable_sort(a+1,a+n+1);
                int pd=0;
                for(int i=1;i<n;i++)if(a[i+1]-a[i]==1)pd=1;
                puts(pd?"NO":"YES");
            }
            else{
                puts("YES");
            }
        }
    }
    return  0;
}