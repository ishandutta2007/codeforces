#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi a(n);
    vi ch;
    vi kin;
    int sum = 0;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        if(a[i] == 1000) kin.pb(i);
        sum += a[i];
        ch.pb(sum);
    }
    int ans = sum;
    int lastk = -1;
    int nextk = 0;
    forn(i,0,n) {
        if(a[i] == 1000) lastk = i;
        while(nextk < n && (nextk <= i || a[nextk] == 2000)) nextk++;
        int kop = ch[i];
        int lf = sum - kop;
        ans = min(ans, kop + max(lf - kop/10, 0));
        if(lastk > 0) {
            int cand = ch[lastk - 1];
            int bon = cand/10;
            int dec = min(1000, bon);
            cand += 1000-dec;
            bon -= dec;
            cand += ch[i] - ch[lastk];
            bon += (ch[i] - ch[lastk]) / 10;
            int lf = sum - ch[i];
            ans = min(ans, cand + max(lf - bon, 0));
        }
        if(nextk < n) {
            int cand = ch[i];
            int bon = cand/10;
            int lf = ch[nextk-1] - ch[i];
            int dec = min(bon, lf);
            cand += lf-dec;
            bon -= dec;
            cand += 1000;
            bon += 100;
            lf = sum - ch[nextk];
            dec = min(bon, lf);
            cand += lf-dec;
            ans = min(ans,cand);
        }
    }
    cout<<ans;
    
}