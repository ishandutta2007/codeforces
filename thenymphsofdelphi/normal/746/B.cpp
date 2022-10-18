#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, ss;
    cin >> s;
    ss = s;
    int l = n / 2 - 1, r = n / 2;
    if (n % 2 == 1){
        ss[r] = s[0];
        s.erase(s.begin());
        n--;
        r++;
    }
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            ss[l] = s[i];
            l--;
        }
        else{
            ss[r] = s[i];
            r++;
        }
    }
    cout << ss;
}