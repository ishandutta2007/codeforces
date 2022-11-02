#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
//    int T;
//    cin >> T;
//    while (T--) {
    long long  n, t = 0, a, d, ans = 1, f1, f2, cnt = 0, num = 0, cnt2 = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++){
//        cout << num <<' ';
        cin >> a;
//        cout << i << ' ' << a << endl;
        if (a == -1){
            if(t == 2 && num <= 0) {
                    ans++, t = 0, cnt = 0, cnt2 = 0, num = 0;
//                    cout << i << a<< ":1 ";
            }
            if(t) cnt2++;
                else cnt++;
            num += d;
        }
        else {
            if (t == 0) {
                f1 = a;
                t = 1;
                cnt2 = 0;
            }
            else if (t == 1) {
                f2 = a;
                d = (f2 - f1) / (cnt2 + 1);
                if((f2 - f1) % (cnt2 + 1) || f1 - cnt * d <= 0)
                {
                    ans++;
                    f1 = a;
                    cnt2 = 0;
                    cnt = 0;
                    num = 0;
//                    cout << i << a<< ":2 ";
                }
                else {
                    t = 2;
                    num = d + a;
                }
            }
            else {
                if (num == a) {
                    num += d;
                }
                else {
                    ans ++;
//                    cout << i << a << ":3  ";
                    f1 = a;
                    cnt = 0;
                    cnt2 = 0;
                    num = 0;
                    t = 1;
                }
            }
        }
    }
    cout << ans << endl;
//    }
}