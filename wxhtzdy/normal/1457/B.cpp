#include <bits/stdc++.h>
using namespace std;
int main(){
    int tt=1;scanf("%i",&tt);
    while(tt--){
        int n,k;scanf("%i %i",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        int ans=n;
        for(int c=1;c<=100;c++){
            vector<int> pos;
            for(int j=0;j<n;j++)if(a[j]!=c)pos.push_back(j);
            if((int)pos.size()==0){
                ans=0;
                break;
            }
            int tmp=1,lst=pos[0];
            for(int j:pos){
                if((j-lst)>=k)tmp++,lst=j;
            }
            ans=min(ans,tmp);
        }
        printf("%i\n",ans);
    }
    return 0;
}