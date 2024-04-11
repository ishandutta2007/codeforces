//ponelo me je ponelo
//bila si ti savrsena po meri
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,k;scanf("%i %i",&n,&k);
        vector<int> sum(k*2+1),a(n);
        for(int &i:a)scanf("%i",&i);
        auto add=[&](int l,int r,int f){
            sum[l]+=f;
            sum[r+1]-=f;
        };
        for(int i=0;i<n/2;i++){
            int x=a[i],y=a[n-i-1];
            if(x>y)swap(x,y);
            add(2,x,2);
            add(x+1,x+y-1,1);
            add(x+y+1,k+y,1);
            add(k+y+1,k*2,2);
        }
        int ans=n;
        for(int i=2;i<=2*k;i++){
            sum[i]+=sum[i-1];
            ans=min(ans,sum[i]);
        }
        printf("%i\n",ans);
    }
    return 0;
}