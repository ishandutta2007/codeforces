#include <bits/stdc++.h>
using namespace std;

int can[1005][27][27][2], n, p, i, j, k;
string s, t;
bool sol(int d,int a,int b,int m){
    if(d==s.size()) return !m;
    else if(can[d][a][b][m]!=-1) return can[d][a][b][m];
    can[d][a][b][m] = 0;
    for(int i=(m?s[d]-'a':0);i<p;i++){
        if(i==a||i==b) continue;
        if(sol(d+1,b,i,m&&i==s[d]-'a'))
            can[d][a][b][m] = 1;
    }
    return can[d][a][b][m];
}
void rec(int d,int a,int b,int m){
    if(d==s.size()) return;
    for(int i=(m?s[d]-'a':0);i<p;i++){
        if(i==a||i==b) continue;
        if(sol(d+1,b,i,m&&i==s[d]-'a')){
            t.push_back(i+'a');
            rec(d+1,b,i,m&&i==s[d]-'a');
            return;
        }
    }
}
int main(){
    cin >> n >> p >> s;
    memset(can, -1, sizeof(can));
    if(!sol(0,26,26,1)) printf("NO\n");
    else rec(0,26,26,1), printf("%s\n",t.c_str());
    return 0;
}