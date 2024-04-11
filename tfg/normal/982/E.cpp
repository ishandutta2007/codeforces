#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long ll;
typedef std::pair<ll, ll> ii;

ll safemod(ll a, ll m) {
    return (a % m + m) % m;
}

ll modinverse(ll a, ll b, ll s0 = 1, ll s1 = 0) {
    if(!b) {
        return s0;
    } else {
        return modinverse(b, a % b, s1, s0 - s1 * (a / b));
    }
}

ll gcd(ll a, ll b) {
    if(!b) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll mul(ll a, ll b, ll m) {
	a = safemod(a, m);
	b = safemod(b, m);
    ll ans = 0;
    for(; b > 0; b /= 2) {
    	if(b & 1) {
    		ans = (ans + a) % m;
    	}
    	a = (a + a) % m;
    }
    return ans;
}

struct equation {
    equation(ll a, ll m){ans = safemod(a, m), mod = m, valid = true;}
    equation(){valid = false;}
    equation(equation a, equation b) {
        if(!a.valid || !b.valid) {
            valid = false;
            return;
        }
        ll g = gcd(a.mod, b.mod);
        if((a.ans - b.ans) % g != 0) {
            valid = false;
            return;
        }
        valid = true;
        mod = a.mod * (b.mod / g);
        ans = a.ans +
              mul(
                      mul(a.mod, modinverse(a.mod, b.mod), mod),
                      (b.ans - a.ans) / g
              , mod);
        ans = safemod(ans, mod);
    }
    ll mod, ans;
    bool valid;

    void print() {
        if(!valid)
            std::cout << "equation is not valid\n";
        else
            std::cout << "equation is " << ans << " mod " << mod << '\n';
    }
};

int main() {
	ll n, m, px, py, vx, vy;
	std::cin >> n >> m >> px >> py >> vx >> vy;
	if(vx == 0) {
		if(px == n || px == 0) {
			std::cout << px << ' ' << (vy == 1 ? m : 0) << std::endl;
		} else {
			std::cout << "-1\n";
		}
	} else if(vy == 0) {
		if(py == m || py == 0) {
			std::cout << (vx == 1 ? n : 0) << ' ' << py << std::endl;
		} else {
			std::cout << "-1\n";
		}
	} else {
		std::vector<ii> hmm;
		for(int i = 0; i < 4; i++) {
			//std::cout << i%2*n << ' ' << i/2*m << '\n';
			equation cur(equation((i%2*n - px) * vx, 2*n), equation((i/2*m-py)*vy, 2*m));
			//cur.print();
			if(cur.valid) {
				hmm.push_back(ii(cur.ans, i));
			}
		}
		std::sort(hmm.begin(), hmm.end());
		if(hmm.size() == 0) {
			std::cout << "-1\n";
		} else {
			int idx = hmm[0].second;
			std::cout << idx%2*n << ' ' << idx/2*m << '\n';
		}
	}
}