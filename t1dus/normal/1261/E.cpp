#include<bits/stdc++.h>
using namespace std;

int n,a[1005];
int ans[1005][1005];
int nxt[1005];

signed main(){
    cin >> n;
    cout << n+1 << "\n";
    for(int i = 0; i < n+1; i ++) nxt[i] = n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        int j = 0;
        while(j < n+1){
            if(a[i] == 0) ans[j++][i] = 0;
            else if(a[i] == (n+1-j)){
                ans[j++][i] = 1;
                a[i]--;
            }
            else{
                if(nxt[j] > j){
                    int ones = min(nxt[j]-j,a[i]);
                    for(int k = j; k <= nxt[j]; k++){
                        if(ones){
                            ans[k][i] = 1;
                            a[i]--;
                            ones--;
                        }
                        else ans[k][i] = 0;
                    }
                    j = nxt[j]+1;
                }
                else{
                    if(a[i] > 1){
                        ans[j++][i] = 1;
                        a[i]--;
                    }
                    else ans[j++][i] = 0;
                }
            }
        }
        for(j = 0; j < n; j++){
            if(ans[j][i] != ans[j+1][i]) nxt[j] = j;
        }
        for(j = n-1; j >= 0; j --) nxt[j] = min(nxt[j],nxt[j+1]);
    }
    for(int i = 0; i < n+1; i ++){
        for(int j = 0; j < n; j ++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}