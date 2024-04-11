#include <bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int main(){
    scanf("%s",&s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='n')continue;
        bool ok=0;
        for(char c:{'a','e','i','o','u'})if(c==s[i])ok=1;
        if(ok)continue;
        if(i==n-1)return 0*printf("NO");
        bool t=0;
        for(char c:{'a','e','i','o','u'})if(c==s[i+1])t=1;
        if(!t)return 0*printf("NO");
    }
    printf("YES");
    return 0;
}