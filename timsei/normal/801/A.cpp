#include<bits/stdc++.h>
using namespace std;

const int N = 205;
char s[N];

int now , l , ans;

int main() {
    scanf("%s",s);
    int l = strlen(s);
    int ans = 0;
    for(int i = 0;i < l - 1;i ++) {
        if(s[i] =='V' && s[i + 1] == 'K') {
            ans ++;
        }
    }
    for(int i = 0;i <l;i ++) {
        if(s[i] == 'V') s[i] = 'K';else s[i] = 'V';
        now = 0;
        for(int j = 0;j<l - 1;j ++) {
            if(s[j]=='V' && s[j + 1] =='K') now ++;
        }
        if(now > ans) ans = now;
        if(s[i] == 'V') s[i] = 'K';else s[i] = 'V';
    }
    cout<<ans;
}