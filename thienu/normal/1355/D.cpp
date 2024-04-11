#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve(){
    int n, s;
    scanf("%d %d", &n, &s);
    if(s >= 2 * n){
        printf("YES\n");
        for(int i = 0; i < n-1; i++){
            printf("%d ", 1);
        }
        printf("%d\n", s-n+1);
        printf("%d\n", n);
    }
    else{
        printf("NO\n");
    }
}

int main(){
    solve();
    return 0;
}