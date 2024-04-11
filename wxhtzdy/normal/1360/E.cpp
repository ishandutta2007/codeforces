#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        char s[n][n];
        for(int i=0;i<n;i++)scanf("%s",&s[i]);
        bool ok=1;
        for(int i=0;i<n-1;i++)for(int j=0;j<n-1;j++)if(s[i][j]=='1'){
            if(s[i+1][j]=='0'&&s[i][j+1]=='0')ok=0;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}