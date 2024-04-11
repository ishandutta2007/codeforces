#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int cnt[26];
int main(){
    int n,k;scanf("%i%i",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        int j=i;
        while(j+1<=n&&s[i]==s[j+1])j++;
        cnt[s[i]-'a']+=(j-i+1)/k;
        i=j;
    }
    int ans=0;
    for(int i=0;i<26;i++)ans=max(ans,cnt[i]);
    printf("%i",ans);
    return 0;
}