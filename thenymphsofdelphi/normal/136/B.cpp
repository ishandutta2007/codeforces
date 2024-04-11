#include<bits/stdc++.h>
using namespace std;
#define int long long

string cnv(int a){
    string ans = "";
    while (a != 0){
        ans.push_back(a % 3 + '0');
        a /= 3;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int cnvb(string s){
    int ans = 0;
    for (int i = 0; i < s.length(); i++){
        ans *= 3;
        ans += s[i] - '0';
    }
    return ans;
}

signed main(){
    int a, b, c;
    string s, t, r;
    cin >> a >> c;
    s = cnv(a);
    r = cnv(c);
    while (s.length() < r.length()){
        s = '0' + s;
    }
    while (s.length() > r.length()){
        r = '0' + r;
    }
    //cout << s << endl << r << endl;
    for (int i = 0; i < s.length(); i++){
        int dif = r[i] - s[i];
        if (dif < 0){
            dif += 3;
        }
        if (dif < 0){
            dif += 3;
        }
        t.push_back(dif + '0');
    }
    cout << cnvb(t);
}