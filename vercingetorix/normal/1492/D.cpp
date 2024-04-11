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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int a,b,k;
    cin>>a>>b>>k;
    if(a == 0 || b==1) {
        if(k!=0) {
            cout<<"No\n";
            return 0;
        }
        printf("Yes\n");
        printf("%s", string(b,'1').c_str());
        printf("%s\n", string(a,'0').c_str());
        printf("%s", string(b,'1').c_str());
        printf("%s\n", string(a,'0').c_str());
        return 0;
    }
    if(k >= a+b - 1) {
        cout<<"No\n";
        return 0;
    }
    string x(a+b, '1');
    string y(a+b, '1');
    y[1] = '0';
    x[k+1] = '0';
    a--;
    int pt = 2;
    while(a > 0) {
        if(pt == k+1) pt++;
        x[pt] = '0';
        y[pt] = '0';
        pt++;
        a--;
    }
    printf("Yes\n");
    printf("%s\n", x.c_str());
    printf("%s\n", y.c_str());
    
    
}