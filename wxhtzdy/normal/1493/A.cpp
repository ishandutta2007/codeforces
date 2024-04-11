#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,k;scanf("%i%i",&n,&k);
        vector<int> ans;
        for(int i=k+1;i<=n;i++)ans.pb(i);
        for(int i=(k+1)/2;i<k;i++)ans.pb(i);
        printf("%i\n",ans.size());
        for(int i:ans)printf("%i ",i);
        printf("\n");
    }
    return 0;
}