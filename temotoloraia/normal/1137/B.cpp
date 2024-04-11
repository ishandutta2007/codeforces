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

const int N = 500005;

string s, t;
string ss;
int A, B;
int n;

int l, r;

int I;

int z[N];

int p, q, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '0')
            A++;
        else
            B++;
    }
    n = (int)t.size();
    I = n;
    for (int i = 1; i < n; i++){
        if (i <= r)
            z[i] = min (z[i - l], r - i + 1);
        while (i + z[i] < n && t[i + z[i]] == t[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        if (i + z[i] == n)
            I = min (I, i);
    }
    for (int i = 0; i < n; i++){
        if (t[i] == '0')
            p++;
        else
            q++;
    }
    for (int i = n - I; i < n; i++){
        ss += t[i];
    }
    for (int i = 0; i < I; i++){
        if (ss[i] == '0')
            x++;
        else
            y++;
    }
    if (A < p || B < q){
        cout << s << endl;
        return 0;
    }
    cout << t;
    A -= p;
    B -= q;
    while (A >= x && B >= y){
        cout << ss;
        A -= x;
        B -= y;
    }
    for (int i = 0; i < A; i++)
        cout << "0";
    for (int i = 0; i < B; i++)
        cout << "1";
    cout << endl;
    return 0;
}