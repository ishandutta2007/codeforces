#include<bits/stdc++.h>
using namespace std;

int main(){
    long long nd, q, n, par, lev, now, dis;
    string a;
    char last;
    cin >> nd >> q;
    par = (nd + 1) / 2;
    while (q--){
        cin >> n >> a;
        lev = log2(n & -(n));
        now = n;
        dis = (n & -(n));
        last = ((n & (int)((n & -(n)) * 2)) ? 'R' : 'L');
        //cout << lev << " " << now << " " << dis << " " << last << "\n";
        for (int i = 0; i < a.length(); i++){
            if (a[i] == 'L'){
                if (lev == 0){
                    //cout << lev << " " << now << " " << dis << " " << last << "\n";
                    continue;
                }
                lev--;
                dis /= 2;
                now -= dis;
                last = ((now & (int)((now & -(now)) * 2)) ? 'R' : 'L');
            }
            if (a[i] == 'R'){
                if (lev == 0){
                    //cout << lev << " " << now << " " << dis << " " << last << "\n";
                    continue;
                }
                lev--;
                dis /= 2;
                now += dis;
                last = ((now & (int)((now & -(now)) * 2)) ? 'R' : 'L');
            }
            if (a[i] == 'U'){
                if (lev == log2(nd + 1) - 1){
                    //cout << lev << " " << now << " " << dis << " " << last << "\n";
                    continue;
                }
                lev++;
                if (last == 'L'){
                    now += dis;
                }
                else if (last == 'R'){
                    now -= dis;
                }
                last = ((now & (int)((now & -(now)) * 2)) ? 'R' : 'L');
                dis *= 2;
            }
            //cout << lev << " " << now << " " << dis << " " << last << "\n";
        }
        cout << now << "\n";
    }
}