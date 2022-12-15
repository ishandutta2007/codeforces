#include <bits/stdc++.h>
using namespace std;

string s, ans, o[3], t[3];
int n, p[10004], i, j;

int main(){
    cin >> s; n = s.size();
    for(i=0;i<n;i++){
        o[0] += 'a'+(i/26/26);
        o[1] += 'a'+((i/26)%26);
        o[2] += 'a'+(i%26);
    }
    for(i=0;i<3;i++){
        printf("? %s\n",o[i].c_str());
        fflush(stdout);
        cin >> t[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(o[0][i]==t[0][j]&&o[1][i]==t[1][j]&&o[2][i]==t[2][j]){
                p[i] = j;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        ans += s[p[i]];
    }
    printf("! %s\n",ans.c_str());
    fflush(stdout);
    return 0;
}