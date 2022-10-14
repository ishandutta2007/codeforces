#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char s[n];
    scanf("%s",&s);
    int cnt=0;
    for(int i=0;i<n;i+=cnt){
        printf("%c",s[i]);
        cnt++;
    }
    return 0;
}