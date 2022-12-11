#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0,pd=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(pd)ans++;
                pd=0;
            }
            else pd=1;
        }
        if(pd)ans++;
        printf("%d\n",min(ans,2));
    }
    return  0;
}