#include <bits/stdc++.h>
using namespace std;

int n, t, i;
string s;

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        int ans = 0, sna = 1, cur = -1;
        cin >> s;
        for(i=0;i<n;i+=2){
            if(s[i] != s[i+1]){
                ans ++;
            }
            else if(s[i] == '0'){
                if(cur == 1) sna ++;
                cur = 0;
            }
            else{
                if(cur == 0) sna ++;
                cur = 1;
            }
        }
        printf("%d %d\n",ans, sna);
    }
    return 0;
}