#include <iostream>
#include <algorithm>
#include <vector>


typedef long long ll;

long long modinverse(long long a, long long b, long long s0 = 1, long long s1 = 0) { return b == 0 ? s0 : modinverse(b, a % b, s1, s0 - s1 * (a / b)); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long mul(long long a, long long b, long long m) {
	long long q = (long double) a * (long double) b / (long double) m;
	long long r = a * b - q * m;
	return (r + m) % m;
}
 
struct Equation {
	Equation(long long a, long long m) { mod = m, ans = a, valid = true; }
	Equation() { valid = false; }
	Equation(Equation a, Equation b) {
		if(!a.valid || !b.valid) {
			valid = false;
			return;
		}
		long long g = gcd(a.mod, b.mod);
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
		ans = (ans % mod + mod) % mod;
	}
	long long mod, ans;
	bool valid;
};


ll lcm(ll a, ll b)
{
    return (ll) std::min((long double) 1e13, (long double) a * (b / gcd(a, b)));
}

std::vector<ll> a, primes, divs;
std::vector<int> pos[1010];

int main()
{
    ll n, m;
    std::cin >> n >> m;
    int k;
    std::cin >> k;
    ll tot = 1;
    for(int i = 0; i < k; i++)
    {
        ll temp;
        std::cin >> temp;
        tot = lcm(tot, temp);
        a.push_back(temp);
    }
    //std::cout << "lcm is " << tot << '\n';
    if(tot > n)
    {
        std::cout << "NO\n";
        return 0;
    }

    ll x = tot;
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i != 0)
            continue;
        ll cur = i;
        while(x % i == 0)
        {
            primes.push_back(i);
            divs.push_back(cur);
            cur *= i;
            x /= i;
        }
    }
    if(x != 1)
    {
        primes.push_back(x);
        divs.push_back(x);
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < divs.size(); j++)
        {
            if(a[i] % divs[j] == 0)
            {
                if(pos[j].size() != 0)
                {
                    if(i - pos[j].back() != divs[j])
                    {
                        //std::cout << "got " << divs[j] << " on " << i << " should be on " << pos[j].back() + divs[j] << '\n';
                        std::cout << "NO\n";
                        return 0;
                    }
                }
                pos[j].push_back(i);
            }
            else if(pos[j].size() != 0 && i - pos[j].back() == divs[j])
            {
                //std::cout << "didn't find " << divs[j] << " on position " << i << ", last was " << pos[j].back() << '\n';
                std::cout << "NO\n";
                return 0;
            }
            else if(pos[j].size() == 0 && i + 1 >= divs[j])
            {
                //std::cout << "casa dos pombos em " << divs[j] << '\n';
                std::cout << "NO\n";
                return 0;
            }
        }
    }
    Equation ans (0, 1);
    for(int i = 0; i < divs.size(); i++)
    {
        if(pos[i].size() == 0)
            continue;
        ans = Equation(ans, Equation((divs[i] - pos[i][0])%divs[i], divs[i]));
    }
    if(!ans.valid)
    {
        //std::cout << "equation not valid\n";
        std::cout << "NO\n";
        return 0;
    }
    if(ans.ans == 0)
        ans.ans += tot;
    //std::cout << "first position should be " << ans.ans << '\n';
    if(ans.ans + k - 1 > m)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
}