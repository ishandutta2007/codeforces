#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[105];scanf("%s",&s);
    bool ok=1;
    for(int i=1;i<strlen(s);i++)if(s[i]>='a')ok=0;
    if(ok){
        for(int i=0;i<strlen(s);i++){
            if(s[i]>='a')s[i]-='a'-'A';
            else s[i]+='a'-'A';
        }
    }
    printf("%s",s);
    return 0;
}