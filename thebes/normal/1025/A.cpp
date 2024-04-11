#include <bits/stdc++.h>
using namespace std;

int cnt[26], n, i, fl, fl2;
char ch;

int main(){
    scanf("%d",&n); getchar();
    for(i=0;i<n;i++){
        ch = getchar();
        cnt[ch-'a']++;
    }
    for(i=0;i<26;i++){
        if(cnt[i]>1) fl2=1;
        else if(cnt[i]==1) fl++;
    }
    if(fl2||fl<=1) printf("Yes\n");
    else printf("No\n");
    return 0;
}