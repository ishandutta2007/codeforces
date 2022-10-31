#include <bits/stdc++.h>
using namespace std;

int cnt[2][26],n[2];
char str[2][101];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<2;i++) scanf("%s",str[i]), n[i] = strlen(str[i]);
        for(int j=0;j<n[0];j++) cnt[0][str[0][j]-'a']++;

        bool f = false;
        for(int j=0;j<=n[1]-n[0];j++) {
            memset(cnt[1],0,sizeof(cnt[1]));
            for(int k=0;k<n[0];k++) {
                cnt[1][str[1][j+k]-'a']++;
            }
            int t=1;
            for(int k=0;k<26;k++) if(cnt[0][k]!=cnt[1][k]) {
                t=0;
                break;
            }
            if(t) {
                f=true;
                break;
            }
        }
        puts(f ? "YES" : "NO");
    }
    return 0;
}