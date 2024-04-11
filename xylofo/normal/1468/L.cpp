#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

unordered_set<ll> uniqueFactors(ll x) {
  unordered_set<ll> retvalue;
  vector<ull> temp = factor(x);
  trav(elem, temp) retvalue.insert(elem);
  return retvalue;
}

bool okNumber(ll num, unordered_map<ll,pii>& firstTwoForFactor) {
  unordered_set<ll> uf = uniqueFactors(num);
  trav(elem, uf) if (firstTwoForFactor.count(elem) == 0 ||
                     firstTwoForFactor[elem].second == -1) {
    return false;
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  //cerr << endl;


  int k, n; cin >> n >> k;
  vector<ll> x(n);
  rep(i,0,n) cin >> x[i];

  unordered_map<ll, pii> firstTwoForFactor;
  vector<pair<ll,ll>> leftOver;
  trav(elem, x) {
    unordered_set<ll> uf = uniqueFactors(elem);
    bool added = false;
    if (sz(uf) == 1) {
      ll p = *uf.begin();
      if (firstTwoForFactor.count(p) == 0) {
        firstTwoForFactor[p] = pii(elem, -1);
        added = true;
      }
      else if (firstTwoForFactor[p].second == -1) {
        firstTwoForFactor[p].second = elem;
        added = true;
      }
    }
    if (!added) {
      leftOver.push_back(pii(sz(uf), elem));
    }
  }
  sort(all(leftOver));
  //trav(elem, leftOver) {
  //  cerr << elem.first << " " << elem.second << endl;
  //}
  //trav(elem,firstTwoForFactor) {
  //  cerr << elem.first << ": " << elem.second.first << "," << elem.second.second << endl;
  //}

  vector<ll> ans;
  unordered_set<ll> usedPrimes;
  ll i = 0;
  if (k % 2) {
    while(i < sz(leftOver)) {
      if (okNumber(leftOver[i].second, firstTwoForFactor)) {
        if (leftOver[i].first * 2 + 1 > k) {
          cout << 0 << endl;
          return 0;
        }
        // choose elem
        ans.push_back(leftOver[i].second);
        k--;
        unordered_set<ll> uf = uniqueFactors(leftOver[i].second);
        trav(p, uf) {
          pii temp = firstTwoForFactor[p];
          ans.push_back(temp.first);
          ans.push_back(temp.second);
          assert(temp.first != -1 && temp.second != -1);
          k -= 2;
          usedPrimes.insert(p);
        }
        i++;
        break;
      }
      i++;
    }
  }
  if (k % 2) {
    assert(i == sz(leftOver));
  }
  trav(temp, firstTwoForFactor) {
    ll p = temp.first;
    ll a = temp.second.first;
    ll b = temp.second.second;
    if (k == 0 || usedPrimes.count(p) || b == -1) continue;
    ans.push_back(a);
    ans.push_back(b);
    k -= 2;
  }
  while(k && i < sz(leftOver)) {
    if (okNumber(leftOver[i].second, firstTwoForFactor)) {
      ans.push_back(leftOver[i].second);
      k--;
    }
    i++;
  }
  if (k) {
    cout << 0 << endl;
    return 0;
  }
  trav(elem, ans) cout << elem << " ";
  cout << endl;
}