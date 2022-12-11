#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<int,int>mp;
        long long ans=0;
        int mx=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            mx=max(mx,++mp[x]);
        }
        ans=n-mx;
        for(int i=mx;i<n;i+=i){
            ans++;
        }
        printf("%lld\n",ans);
    }
    return  0;
}