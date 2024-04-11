#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const ll N = 1005;

int B[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i - 1] * 2;
    string s;
    while (cin >> s){
        if (s != "start")
            return 0;
        cout << "? 0 1" << endl;
        fflush (stdout);
        cin >> s;
        if (s != "x" && s != "y")
            return 0;
        if (s == "x"){
            cout << "! 1" << endl;
            continue;
        }
        int l = B[29] + 1, r = 1e9;
        for (int i = 0; i < 29; i++){
            int x = B[i], y = B[i + 1];
            cout << "? " << x << " " << y << endl;
            fflush (stdout);
            cin >> s;
            if (s != "x" && s != "y")
                return 0;
            if (s == "x"){
                l = x + 1;
                r = y;
                break;
            }
        }
        while (l < r){
            int mid = (l + r) / 2;
            cout << "? " << l - 1 << " " << mid << endl;
            fflush (stdout);
            cin >> s;
            if (s != "x" && s != "y")
                return 0;
            if (s == "y")
                l = mid + 1;
            else
                r = mid;
        }
        cout << "! " << l << endl;
    }
    return 0;
}