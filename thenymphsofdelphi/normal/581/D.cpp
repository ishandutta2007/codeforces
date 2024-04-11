#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 2e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int x1, y1, x2, y2, x3, y3, n;
char a[N][N];

void print(){
    cout << n << endl;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cout << a[i][j];
        }
        cout << endl;
    }
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    n = sqrt(x1 * y1 + x2 * y2 + x3 * y3);
    if (n * n != x1 * y1 + x2 * y2 + x3 * y3) Ptest(-1);
    if (x1 != n && y1 != n && x2 != n && y2 != n && x3 != n && y3 != n) Ptest(-1);
    if (y1 == n) swap(x1, y1);
    if (x1 == n){
        ForE(i, 1, y1){
            ForE(j, 1, n){
                a[i][j] = 'A';
            }
        }
        int m = n - y1;
        //======================================
        if (y2 == m) swap(x2, y2);
        if (x2 == m){
            ForE(i, y1 + 1, n){
                ForE(j, 1, y2){
                    a[i][j] = 'B';
                }
            }
            if (y3 == m) swap(x3, y3);
            if (x3 == m){
                ForE(i, y1 + 1, n){
                    ForE(j, y2 + 1, n){
                        a[i][j] = 'C';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y2 == n) swap(x2, y2);
        if (x2 == n){
            ForE(i, y1 + 1, y1 + y2){
                ForE(j, 1, n){
                    a[i][j] = 'B';
                }
            }
            if (y3 == n) swap(x3, y3);
            if (x3 == n){
                ForE(i, y1 + y2 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'C';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        //======================================
        if (y3 == m) swap(x3, y3);
        if (x3 == m){
            ForE(i, y1 + 1, n){
                ForE(j, 1, y3){
                    a[i][j] = 'C';
                }
            }
            if (y2 == m) swap(x2, y2);
            if (x2 == m){
                ForE(i, y1 + 1, n){
                    ForE(j, y3 + 1, n){
                        a[i][j] = 'B';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y3 == n) swap(x3, y3);
        if (x3 == n){
            ForE(i, y1 + 1, y1 + y3){
                ForE(j, 1, n){
                    a[i][j] = 'C';
                }
            }
            if (y2 == n) swap(x2, y2);
            if (x2 == n){
                ForE(i, y1 + y3 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'B';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
    }
    if (y2 == n) swap(x2, y2);
    if (x2 == n){
        ForE(i, 1, y2){
            ForE(j, 1, n){
                a[i][j] = 'B';
            }
        }
        int m = n - y2;
        //======================================
        if (y1 == m) swap(x1, y1);
        if (x1 == m){
            ForE(i, y2 + 1, n){
                ForE(j, 1, y1){
                    a[i][j] = 'A';
                }
            }
            if (y3 == m) swap(x3, y3);
            if (x3 == m){
                ForE(i, y2 + 1, n){
                    ForE(j, y1 + 1, n){
                        a[i][j] = 'C';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y1 == n) swap(x1, y1);
        if (x1 == n){
            ForE(i, y2 + 1, y2 + y1){
                ForE(j, 1, n){
                    a[i][j] = 'A';
                }
            }
            if (y3 == n) swap(x3, y3);
            if (x3 == n){
                ForE(i, y2 + y1 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'C';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        //======================================
        if (y3 == m) swap(x3, y3);
        if (x3 == m){
            ForE(i, y2 + 1, n){
                ForE(j, 1, y3){
                    a[i][j] = 'C';
                }
            }
            if (y1 == m) swap(x1, y1);
            if (x1 == m){
                ForE(i, y2 + 1, n){
                    ForE(j, y3 + 1, n){
                        a[i][j] = 'A';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y3 == n) swap(x3, y3);
        if (x3 == n){
            ForE(i, y2 + 1, y2 + y3){
                ForE(j, 1, n){
                    a[i][j] = 'C';
                }
            }
            if (y1 == n) swap(x1, y1);
            if (x1 == n){
                ForE(i, y2 + y3 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'A';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
    }
    if (y3 == n) swap(x3, y3);
    if (x3 == n){
        ForE(i, 1, y3){
            ForE(j, 1, n){
                a[i][j] = 'C';
            }
        }
        int m = n - y3;
        //======================================
        if (y1 == m) swap(x1, y1);
        if (x1 == m){
            ForE(i, y3 + 1, n){
                ForE(j, 1, y1){
                    a[i][j] = 'A';
                }
            }
            if (y2 == m) swap(x2, y2);
            if (x2 == m){
                ForE(i, y3 + 1, n){
                    ForE(j, y1 + 1, n){
                        a[i][j] = 'B';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y1 == n) swap(x1, y1);
        if (x1 == n){
            ForE(i, y3 + 1, y3 + y1){
                ForE(j, 1, n){
                    a[i][j] = 'A';
                }
            }
            if (y2 == n) swap(x2, y2);
            if (x2 == n){
                ForE(i, y3 + y1 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'B';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        //======================================
        if (y2 == m) swap(x2, y2);
        if (x2 == m){
            ForE(i, y3 + 1, n){
                ForE(j, 1, y2){
                    a[i][j] = 'B';
                }
            }
            if (y1 == m) swap(x1, y1);
            if (x1 == m){
                ForE(i, y3 + 1, n){
                    ForE(j, y2 + 1, n){
                        a[i][j] = 'A';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
        if (y2 == n) swap(x2, y2);
        if (x2 == n){
            ForE(i, y3 + 1, y3 + y2){
                ForE(j, 1, n){
                    a[i][j] = 'B';
                }
            }
            if (y3 == n) swap(x3, y3);
            if (x3 == n){
                ForE(i, y3 + y2 + 1, n){
                    ForE(j, 1, n){
                        a[i][j] = 'A';
                    }
                }
                print();
            }
            cout << -1;
            return 0;
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/