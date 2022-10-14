#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,k;scanf("%i %i",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        map<int,int> col;
        for(int i=0;i<n;i++){
            if(col[a[i]]==0){
                if(k-a[i]!=a[i]){
                    if(col[k-a[i]]==0)col[k-a[i]]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==k-a[i]){
                printf("%i ",cnt%2);
                cnt++;
            }else printf("%i ",col[a[i]]);
        }
        printf("\n");
    }
    return 0;
}