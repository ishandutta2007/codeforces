#include <bits/stdc++.h>

using namespace std;

char s[105];

int cnt, ans;

int main(){
    int n, d; scanf("%d%d", &n, &d);
    for(int i = 0; i < d; i++){
        scanf("%s", s);
        bool ok = true;
        for(int j = 0; j < n; j++)if(s[j] != '1')ok = false;
        if(!ok)cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}