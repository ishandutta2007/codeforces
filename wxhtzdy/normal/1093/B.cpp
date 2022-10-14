#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        char s[1050];scanf("%s",&s);
        int n=(int)strlen(s);
        sort(s,s+n);
        bool ok=1;
        for(int i=1;i<n;i++)if(s[i]!=s[i-1])ok=0;
        if(ok)printf("-1\n");
        else printf("%s\n",s);
    }
    return 0;
}