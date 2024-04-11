#include<bits/stdc++.h>
using namespace std;

int main(){
    bool inpar = 0;
    string s;
    int n, cnt = 0, mx = 0, t = 0;
    cin >> n >> s;
    s += '_';
    n++;
    for (int i = 0; i < n; i++){
        if (s[i] == '_'){
            if (t != 0){
                if (inpar){
                    cnt++;
                    //cout << i << ' ' << t << endl;
                }
                else{
                    mx = max(mx, t);
                }
                t = 0;
            }
            continue;
        }
        else if (s[i] == '('){
            if (t != 0){
                if (inpar){
                    cnt++;
                    //cout << i << endl;
                }
                else{
                    mx = max(mx, t);
                }
                t = 0;
            }
            inpar = 1;
            t = 0;
            continue;
        }
        else if (s[i] == ')'){
            if (t != 0){
                if (inpar){
                    cnt++;
                    //cout << i << endl;
                }
                else{
                    mx = max(mx, t);
                }
                t = 0;
            }
            inpar = 0;
            continue;
        }
        else{
            t++;
        }
    }
    cout << mx << ' ' << cnt;
}