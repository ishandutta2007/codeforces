#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    char s[n];scanf("%s",s);
    vector<int> cnt(26);
    for(int i=0;i<n;i++)cnt[s[i]-'a']++;
    bool ok=false;
    for(int i=0;i<26;i++){
        if(cnt[i]==n||cnt[i]>=2)ok=true;
    }
    if(ok)printf("Yes");
    else printf("No");
    return 0;
}