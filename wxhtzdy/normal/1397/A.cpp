#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        int cnt[26];
        for(int i=0;i<26;i++)cnt[i]=0;
        for(int i=0;i<n;i++){
            char a[1005];
            scanf("%s",&a);
            for(int j=0;j<strlen(a);j++)cnt[(int)(a[j]-'a')]++;
        }
        bool ok=1;
        for(int i=0;i<26;i++)if(cnt[i]%n!=0)ok=0;
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}