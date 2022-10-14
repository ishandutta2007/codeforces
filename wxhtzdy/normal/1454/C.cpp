#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n];
        map<int,int> res;
        map<int,int> was;
        int ans=n;
        for(int i=0;i<n;i++){
            scanf("%i",&a[i]);
            if(!was[a[i]]){
                res[a[i]]=(i!=0)+1;
                was[a[i]]=1;
            }
            else{
                //res[a[i]]+=(a[i-1]!=a[i]&&i!=(n-1));
                //if(a[i]==a[i-1]&&i==(n-1))res[a[i]]--;
                res[a[i]]+=a[i]!=a[i-1];
            }
            //if(a[i]==3)printf("%i\n",res[a[i]]);
        }
        res[a[n-1]]--;
        bool same=1;
        for(int i=1;i<n;i++)if(a[i]!=a[0])same=0;
        if(same){
            printf("0\n");
            continue;
        }

        for(int i=0;i<n;i++){
            //printf("%i %i\n",a[i],res[a[i]]);
            ans=min(ans,res[a[i]]);
        }
        printf("%i\n",ans);
    }
}