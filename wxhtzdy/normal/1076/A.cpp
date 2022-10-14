#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char s[n];
    scanf("%s",&s);
    int c=0,j=n-1;
    for(int i=0;i<n-1;i++){
        int ch=(int)(s[i]-'0');
        if(s[i]>s[i+1]){j=i;break;}
    }
    for(int i=0;i<n;i++){
        if(i==j)continue;
        printf("%c",s[i]);
    }
    return 0;
}