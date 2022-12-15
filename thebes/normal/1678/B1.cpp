#include <bits/stdc++.h>
using namespace std;

int n, t, i;
string s;

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        int ans = 0;
        cin >> s;
        for(i=0;i<n;i+=2){
            if(s[i] != s[i+1]){
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}