#include<bits/stdc++.h>

// Include file

using namespace std;
using ll = long long;

#define ar array
#define vt vector
#define pii pair<int, int>
#define mp make_pair
#define psh push_back
#define rel pop_back
#define que queue

// I need a bad bish, addison rae

#define lb lower_bound
#define ub upper_bound
#define str string
#define FOR(i, v) for(int i =0; i < v; i++)
#define FORd(i, v) for(int i = v; i>=0; i--)
#define make_graph(a) vector<int> a[10000]
#define ld loung double

// You know, we know, psych you don't know...
const int subs = 20;
const int temps = 1e4 + subs;
int a[temps];
int b[temps];
int c[temps];





void solve(int n=0) {
    cout << 5*n;
}



namespace number_theory {
    const int mod =(int) 1e9+7;
    int gcd(int x, int y) {
        return __gcd(x, y);
    }
    ll gcd(ll x, ll y) {
        return __gcd(x, y);
    }
    vector<int> sieve(int x){
        assert(x<100000&&x>1);
        bool a[100000];
        vector<int> s;
        memset(a, 1, sizeof(a));
        // N times, primes occur n / log n times, from 1 to n, which means the efficiency is n log (log n)
        for(int i = 2; i<= x; i++){
            if(a[i]) {
                for(int p = i*i; p<=x; p+=i) {
                    a[p]=0;
                }
            }
        }
        
        for(int i = 2; i<=x; i++){
            if(a[i]) s.push_back(i);
        }
        return s;
    }
    vector<int> factors(int x) {
        set<int> fac;
        vector<int> space;
        for(int i = 1; i<= int(sqrt(x)); i++) {
            if(x%i==0) {
                fac.insert(x/i);
                fac.insert(i);
            }
        }
        
        for(auto &y : fac) {
            space.push_back(y);
        }
        return space;
    }
    int lcm(int x, int y) {
        int ans = x*y/__gcd(x, y);
        return ans;
    }
    bool prime(int x) {
        for(int i = 2; i<=int(sqrt(x)); i++) {
            if(x%i==0) return false;
        }
        return true;
    }
    vector<pair<int, int>> prime_factors(int x) {
        assert(x<10000);
        vector<int> a = sieve(x);
        vector<int> b(10000);
        int n = x;
        for(auto &i : a) {
            while(n%i==0){ 
                n/=i;
                b[i]++;
            }
        }
        vector<pair<int, int>> result;
        for(int i =0; i < 10000; i++) {
            if(b[i]>0) {
                result.push_back(make_pair(i, b[i]));
            }
        }
        return result;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    str a, b;
    cin >> a >> b;
    str ns;
    for(int i =0; i < a.size(); i++) {
        if(a[i]!=b[i]) ns.append("1");
        else ns.append("0");
    }
    cout << ns;
    
    

}