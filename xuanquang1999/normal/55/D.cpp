//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}

int nTest, m[2521], rm[48], lcm[2521][10];
ll l, r, f[19][2][48][2520];

ll Solve(ll x) {
    stringstream ss;
    ss << x;
    string s = ss.str();
    int n = s.length();
//    debug(x);
    memset(f, 0, sizeof f);
    fto(d, 0, s[0]-'0'-1) f[0][1][m[d]][d] = 1;
    fto(d, s[0]-'0', s[0]-'0') f[0][0][m[d]][d] = 1;

    fto(i, 0, n-2) {
        fto(lo, 0, 1) {
            fto(b, 0, 47) {
                fto(r, 0, 2519) {
                    if (f[i][lo][b][r] > 0) {
//                        printf("i: %d %d %d %d\n", i, lo, b, r);
                        int lim = (lo) ? 9 : (s[i+1]-'0');
                        fto(d, 0, lim) {
                            int I = i+1;
                            int LO = lo|(d < (s[i+1]-'0'));
                            int B = m[lcm[rm[b]][d]];
                            int R = (r*10+d)%2520;
                            f[I][LO][B][R] += f[i][lo][b][r];
//                            printf("%d %d %d %d %d %d\n", d, lcm[rm[b]][d], I, LO, B, R);
                        }
                    }
                }
            }
        }
    }

    ll res = 0;
    fto(lo, 0, 1) {
        fto(b, 0, 47) {
            fto(r, 0, 2519) {
                if (r%rm[b] == 0) res += f[n-1][lo][b][r];
            }
        }
    }
//    debug(res);
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("sodep.inp", "r", stdin);
        freopen("sodep.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int cnt = 0;
    m[0] = 0;
    fto(i, 1, 2520) {
        int x = i;
        if (x%2 == 0) x /= 2;
        if (x%2 == 0) x /= 2;
        if (x%2 == 0) x /= 2;
        if (x%3 == 0) x /= 3;
        if (x%3 == 0) x /= 3;
        if (x%5 == 0) x /= 5;
        if (x%7 == 0) x /= 7;
        if (x == 1) {
            m[i] = cnt;
            rm[cnt++] = i;
        }
    }

    fto(i, 1, 2520) {
        lcm[i][0] = i;
        fto(d, 1, 9) lcm[i][d] = i*d/GCD(i, d);
    }

//    fto(i, 1, 20) {
//        fto(d, 0, 9) printf("%d ", lcm[i][d]);
//        puts("");
//    }

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        cin >> l >> r;

        cout << Solve(r)-Solve(l-1) << endl;
    }



    return 0;
}