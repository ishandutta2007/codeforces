#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, l, r, s;
int ans[N];

void solve(){
        scanf("%d%d%d%d", &n, &l, &r, &s);
        if((r - l + 2) * (r - l + 1) / 2 > s){
                printf("-1\n");
                return;
        }
        vector < int > x;
        for(int i = l;i <= r;i++)
                x.push_back(n - i + l);
        if(accumulate(x.begin(), x.end(), 0) < s){
                printf("-1\n");
                return;
        }
        reverse(x.begin(), x.end());
        while(accumulate(x.begin(), x.end(), 0) > s){
                for(int i = 0;i < x.size();i++){
                        if((i == 0 && x[i] > 1) || (i > 0 && x[i] > x[i - 1] + 1)){
                                x[i]--;
                                break;
                        }
                }
        }
        for(int i = 1;i <= n;i++)
                ans[i] = 0;
        for(int i = l;i <= r;i++)
                ans[i] = x[i - l];
        for(int i = 1;i <= n;i++){
                if(ans[i] != 0) continue;
                for(int val = 1;val <= n;val++){
                        bool ok = true;
                        for(int j = 1;j <= n;j++){
                                if(ans[j] == val) ok = false;
                        }
                        if(ok){ ans[i] = val; break; }
                }
        }
        for(int i = 1;i <= n;i++)
                printf("%d ", ans[i]);
        printf("\n");
}

int main(){
        int t;
        scanf("%d", &t);
        while(t--)
                solve();
        return 0;
}