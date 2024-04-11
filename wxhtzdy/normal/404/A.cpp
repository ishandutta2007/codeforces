#include <bits/stdc++.h>
using namespace std;

const int N=305;

char s[N][N];

int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    bool ok=true;
    for(int i=1;i<=n;i++){
        if(s[i][i]!=s[1][1])ok=false;
        if(s[i][n-i+1]!=s[1][1])ok=false;
    }
    set<char> diff;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&i!=n-j+1){
                if(s[i][j]==s[1][1])ok=false;
                diff.insert(s[i][j]);
            }
        }
    }
    if(ok&&(int)diff.size()<=1)printf("YES");
    else printf("NO");
    return 0;
}