#include <bits/stdc++.h>
#define int long long

using namespace std;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

struct query{
    int a, b;
    char c;
    query() {}
    query(int a, int b, char c): a(a), b(b), c(c) {}
};

vector <query> res;

void get_mul(int x, int n) {
    if (n == 1) return;
    if (n % 2 == 0) {
        get_mul(x, n / 2);
        //get_mul(x, n / 2);
        res.push_back(query(x * n / 2, x * n / 2, '+'));
        return;
    }
    get_mul(x, n - 1);
    res.push_back(query(x * (n - 1), x, '+'));
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    set <int> s;
    s.insert(n);
    int a, b = -1;
    while (1) {
        int sm = *s.begin();
        auto uk = s.end();
        int bg = *(--uk);
        res.push_back(query(sm, bg, '+'));
        int nv = sm + bg;
        vector <int> nxt;
        for (int elem : s) {
            res.push_back(query(bg, nv, '^'));
            nxt.push_back(bg ^ nv);
            break;
        }
        s.insert(nv);
        for (int elem : nxt) s.insert(elem);
        //cout << s.size() << endl;
        for (auto x1 : s) {
            for (auto x2 : s) {
                int g = gcd(x1, x2, a, b);
                if (g == 1) {
                    if (a < 0) {
                        a *= -1;
                        b *= -1;
                    }
                    //cout << a << ' ' << b << endl;
                    int v1 = x1 * a;
                    int v2 = x2 * (-b);
                    if ((v1 ^ v2) == 1) {
                        //cout << a << ' ' << b << ' ' << res.size() << en
                        get_mul(x1, a);
                        get_mul(x2, (-b));
                        res.push_back(query(v1, v2, '^'));
                        cout << res.size() << endl;
                        for (auto elem : res) {
                            cout << elem.a << " " << elem.c << " " << elem.b << endl;
                        }
                        return 0;
                    }
                }
                /*if (__gcd(x1, x2) == 1) {
                    a = x1;
                    b = x2;
                    break;
                }*/
            }
        }
    }

    return 0;
}