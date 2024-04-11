#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), pos = 0, fpos = 0, mv = 0;
    for (int i = 0; i < n; i++){
        pos += (s1[i] == '+' ? 1 : -1);
    }
    for (int i = 0; i < n; i++){
        if (s2[i] == '?'){
            mv++;
        }
        else{
            fpos += (s2[i] == '+' ? 1 : -1);
        }
    }
    int dis = pos - fpos;
    double ans;
    if ((dis + mv) % 2 != 0 || mv < abs(dis)){
        cout << "0.000000000";
        return 0;
    }
    else{
        int m = (mv + abs(dis)) / 2;
        int c = 1;
        for (int i = 0; i < m; i++){
            c *= mv - i;
        }
        for (int i = 2; i <= m; i++){
            c /= i;
        }
        ans = (double) c / (1 << mv);
    }
    cout << fixed << setprecision(9) << ans;
}