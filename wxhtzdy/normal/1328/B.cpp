#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,k;scanf("%i %i",&n,&k);
        pair<int,int> pos;
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum+=i;
            if(sum>=k){
                pos.first=n-i-1;
                pos.second=pos.first+1+(sum-k);
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(i==pos.first||i==pos.second)printf("b");
            else printf("a");
        }
        printf("\n");
    }
    return 0;
}