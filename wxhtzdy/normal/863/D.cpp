#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N],t[N],l[N],r[N];
int main(){
    int n,q,m;
    scanf("%i %i %i",&n,&q,&m);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=q;i++)scanf("%i %i %i",&t[i],&l[i],&r[i]);
    while(m--){
        int k;
        scanf("%i",&k);
        for(int i=q;i;i--){
            if(l[i]<=k&&k<=r[i]){
                if(t[i]==2){
                    k=l[i]+r[i]-k;
                }else{
                    if(k==l[i])k=r[i];
                    else k=k-1;
                }
            }
        }
        printf("%i ",a[k]);
    }
    return 0;
}