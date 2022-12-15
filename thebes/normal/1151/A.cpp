#include <bits/stdc++.h>
using namespace std;

const int MN = 55;
string s, t="ACTG";
int n, i, j, ans=1<<30;

int main(){
    cin >> n >> s;
    for(i=0;i<n-3;i++){
        int tmp = 0;
        for(j=0;j<4;j++){
            tmp += min((t[j]-s[i+j]+26)%26,(s[i+j]-t[j]+26)%26);
        }
        ans = min(ans, tmp);
    }
    printf("%d\n",ans);
    return 0;
}