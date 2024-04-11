#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char s[n];
    scanf("%s",&s);
    int a=0,b=0;
    for(int i=0;i<n-1;i++){
        a+=s[i]=='S'&&s[i+1]=='F';
        b+=s[i]=='F'&&s[i+1]=='S';
    }
    if(a>b)printf("YES");
    else printf("NO");
    return 0;
}