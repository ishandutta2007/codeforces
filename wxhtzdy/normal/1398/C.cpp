#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        char a[n];
        scanf("%s",&a);
        int sum=0;
        long long ans=0;
        map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            int dgt=(int)(a[i]-'0');
            sum+=dgt;
            int x=sum-i-1;
            mp[x]++,ans+=mp[x]-1;
        }
        printf("%lld\n",ans);
    }
}