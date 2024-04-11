#include <bits/stdc++.h>
using namespace std;

int dp[150000][6][6],n;
char str[150010];

int get(char ch) {
    if(ch=='o') return 1;
    if(ch=='n') return 2;
    if(ch=='e') return 3;
    if(ch=='t') return 4;
    if(ch=='w') return 5;
    else return 0;
}
    
int DP(int idx,int p1,int p2) {
    if(idx == n) return 0;

    int &ret = dp[idx][p1][p2];
    if(ret!=-1) return ret;

    int nxt = get(str[idx]);
    ret = DP(idx+1, p1, p2) + 1;
    if(!(p1==get('o') && p2==get('n') && nxt==get('e')) && 
            !(p1==get('t') && p2==get('w') && nxt==get('o'))) {
        ret = min(ret, DP(idx+1, p2, nxt));
    }
    return ret;
}

vector<int> ans;
void trace(int idx,int p1,int p2) {
    if(idx == n) return;

    int &ret = dp[idx][p1][p2];
    int nxt = get(str[idx]);
    if(DP(idx+1,p1,p2)+1 == ret) {
        ans.push_back(idx+1);
        trace(idx+1,p1,p2);
    } else {
        trace(idx+1,p2,nxt);
    }
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%s",str);
        n = strlen(str);

        ans.clear();
        for(int i=0;i<n;i++) memset(dp[i], -1, sizeof(dp[i]));
        printf("%d\n", DP(0,0,0));
        trace(0,0,0);
        for(auto &it:ans) printf("%d ",it);
        puts("");
    }
    return 0;
}