#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        int cnt=0,ans=1;
        for(int i=1;i<=n;i++){
            if(i==1||a[i]==a[i-1])cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        printf("%i\n",ans);
    }
    return 0;
}