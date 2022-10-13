#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define srue true
int maxPow[200005];
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int m; scanf("%d",&m);
        int p[m], s[m];
        for(int i=0;i<=n+3;i++) maxPow[i] = 0;
        
        for(int i=0;i<m;i++){
            scanf("%d%d",&p[i],&s[i]);
            maxPow[s[i]] = max(maxPow[s[i]],p[i]);
        }
        for(int i=n;i>=1;i--){
            maxPow[i] = max(maxPow[i],maxPow[i+1]);
        }
        int i = 0;
        int numUse = 0;
        bool work = srue;
        while(i<n && work){
            int j = i;
            int tempMax = 0;
            numUse++;
            while(j<n){
                tempMax = max(tempMax,a[j]);
                int tempS = j-i+1;
                if(maxPow[tempS]>=tempMax){
                    j++;
                }
                else{
                    break;
                }
            }
            if(j==i) work = false;
            else i=j;
        }
        if(work){
            printf("%d\n",numUse);
        }
        else{
            printf("%d\n",-1);
        }
    }
}