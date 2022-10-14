#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char s[n];
    scanf("%s",&s);
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='I')cnt++;
        if(s[i]=='A')ans++;
    }
    if(cnt==0)printf("%i",ans);
    else if(cnt==1)printf("1");
    else printf("0");
    return 0;
}