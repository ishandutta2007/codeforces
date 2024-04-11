#include <iostream>
#include <cstdio>
#include <cstring>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define ll long long
using namespace std;
bool use[10], num = true, num2 = false;
int main(){
    char l[10], r[10], a[10]; cin >> l >> r;
    int lenl = strlen(l), lenr = strlen(r);
    if(lenl == 1) { cout << l[0]; return 0;}
    if(lenl != lenr){
        bool ok = true; int cnt = 2;
        a[0] = '1', a[1] = '0', num = (r[0] == '1' && r[1] == '0');
        rep(i, 2, lenl) {
            if(lenr == lenl + 1 && i > r[i] - '0' && num) { ok = false; break; }
            a[i] = i + '0', num = (num && r[i] == a[i]);
        }
        if(ok) {a[lenl+2] = '\0'; cout << a;}
        else cout << -1;
        return 0;
    }
    a[0] = l[0], use[l[0] - '0'] = true, num2 = a[0] == r[0];
    rep(i, 1, lenl-1){
        bool ok = false;
        rep(j, num ? l[i]-'0' : 0, 9) if(!use[j]) { 
            a[i] = j + '0', use[j] = true, ok = true; 
            if(num2 && j > r[i] - '0') ok = false;
            num = (num && (j == l[i] - '0')), num2 = (num2 && (j == r[i] - '0'));
            break;
        }
        if(!ok) { cout << -1; return 0; }
    }
    rep(i, 0, 10){
        if(a[i] > '9' || a[i] < '0') break;
        cout << a[i];
    }
    return 0;
}