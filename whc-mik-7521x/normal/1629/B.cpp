#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        if(r-l<=k){puts(l==1&&r==1?"NO":"YES");continue;}
        int now=r-l+1-(l%2!=0);
        now=(now+1)>>1;
        puts(r-l+1-now<=k?"YES":"NO");
    }
    return  0;
}