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
    int n,r;
    scanf("%d", &n);
    readv(a,n);
    char c[5];
    scanf("\n%s", c);
    string s(c);
//    cout<<s;
    if (s=="+-" || s=="-+") s="+";
    if(s.size() == 1) {
        forn(i,0,n) {
            cout<<a[i];
            if (i!=n-1) cout<<s[0];
        }
    }
    else if (s=="-*" || s=="*-") {
        cout<<a[0];
        forn(i,1,n) {
            if(a[i] == 0) cout<<'-';
            else cout<<'*';
            cout<<a[i];
        }
    }
    else {
        int l = 0;
        while(l<n) {
            if (a[l] <= 1) {
                if(l!=0) cout<<'+';
                cout<<a[l];
                l++;
                continue;
            }
            int r = l+1;
            while(r<n && a[r] != 0) r++;
            vi val;
            vi pos;
            vi num1;
            int k = l;
            while(k<r) {
                val.pb(a[k]);
                pos.pb(k);
                k++;
                num1.pb(0);
                while(k<r && a[k] == 1) {
                    k++; num1.back()++;
                }
            }
            if(l!=0) cout<<"+";
            int mul = 1;
            for(auto x : val) {
                mul *= x;
                if(mul > 2000000) break;
            }
            if(val.size()>20 || mul > 2000000) {
                forn(i,l,pos.back()+1) {
                    cout<<a[i];
                    if (i != pos.back()) cout<<'*';
                }
                forn(i,0,num1.back()) cout<<"+1";
                l=r;
                continue;
            }
            vs best;
            vll bestval;
            bestval.pb(val[0]);
            best.pb(to_string(val[0]));
            forn(i,1,val.size()) {
                string mall = to_string(a[l]);
                ll ball = 1;
                forn(j,0,i+1) ball*=val[j];
                forn(j,l+1,pos[i]+1) mall += "*" + to_string(a[j]);
                best.pb(mall);
                bestval.pb(ball);
                ll curp = val[i];
                for(int j = i-1; j>=0; j--) {
                    ll pret = curp + num1[j] + bestval[j];
                    if (pret > bestval[i]) {
                        bestval[i] = pret;
                        best[i] = best[j];
                        forn(kk,0,num1[j]) best[i] += "+1";
                        best[i] += "+";
                        forn(m,pos[j+1],pos[i]+1) {
                            best[i]+=to_string(a[m]);
                            if (m!=pos[i]) best[i] += "*";
                        }
                    }
                    curp*=val[j];
                }
            }
            cout<<best.back();
            forn(i,0,num1.back()) cout<<"+1";
            l=r;
            
        }
    }
    
}