#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%i",&a[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1)continue;
            map<int,int> mp;
            for(int k=0;k<n;k++){
                if(k==j)continue;
                mp[a[i][k]]++;
            }
            bool ok=0;
            for(int k=0;k<n;k++){
                if(i==k)continue;
                if(mp[a[i][j]-a[k][j]]>=1)ok=1;
            }
            if(!ok){
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}