#include<bits/stdc++.h>
using namespace std;

int cnt[1000005][2];

signed main(){
    int t; cin >> t;
    while(t --){
        int n; string s;
        cin >> s;
        n = s.length();
        for(int i = 0; i <= 2*n; i ++) cnt[i][0] = cnt[i][1] = 0;
        int cur = n;
        for(int i = 0; i < n; i ++){
            if(s[i] == '0'){
                cnt[cur][0]++;
                cnt[cur-1][1]++;
                cur--;
            }
            else{
                cnt[cur][1]++;
                cnt[cur+1][0]++;
                cur++;
            }
        }
        cur = n;
        while(cnt[cur][0] or cnt[cur][1]){
            if(cnt[cur][0] >= 2){
                cout << "0";
                cnt[cur][0]--;
                cnt[cur-1][1]--;
                cur--;
            }
            else if(cnt[cur][1]){
                cout << "1";
                cnt[cur][1]--;
                cnt[cur+1][0]--;
                cur++;
            }
            else{
                cout << "0";
                cnt[cur][0]--;
                cnt[cur-1][1]--;
                cur--;
            }
        }
        cout << "\n";
    }
}