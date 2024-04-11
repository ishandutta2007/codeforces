#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    string s;
  //  ll ans = 0;
    cin >> n;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    int d = a[0];
    forn(i,1,n) {
        d=gcd(d, a[i]);
    }
    int oddind=-1;
    int oddnum=0;
    vi b(n);
    forn(i, 0 ,n) {
        b[i]=a[i]/d;
        if((a[i]/d) & 1) {
            oddnum++;
            oddind = i;
        }
    }
    if(oddnum!=1) {
        if(d&1) {
            cout<<0<<endl;
            forn(i,0,n) {
                forn(j,0,a[i]) cout<<(char)('a'+i);
            }
            return 0;
        }
        forn(i,0,n) b[i]*=2;
        d/=2;
    }
    if(oddnum != 1) cout<<2*d<<endl;
    else cout<<d<<endl;
    deque<char> ans;
    if(oddnum == 1) {
        ans.pb((char)'a'+oddind);
        b[oddind]--;
    }
    forn(i,0,n) {
        forn(j,0,b[i]/2) {
            ans.pb((char)'a'+i);
            ans.push_front((char)'a'+i);
        }
    }
    forn(i,0,d) for(auto x:ans) cout<<x;
    //cout<<ans;
}