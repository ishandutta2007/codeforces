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
typedef std::vector<vs> vvs;
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
int n,m;
void rd(vvs & a) {
    a.resize(n);
    forn(i,0,n) {
        string s;
        getline(cin,s);
        a[i].resize(m);
        int pt = 0;
        forn(j,0,m) {
            while(pt <= s.size() && s[pt] != ' ' && s[pt] != '\n' && s[pt] != '\0') a[i][j].pb(s[pt++]);
            pt++;
        }
    }
}

struct mv{
    int x1,y1,x2,y2;
    mv(int x1,int y1,int x2,int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d\n", &n, &m);
    vvs a,b;
    rd(a);
    rd(b);
//    forn(i,0,n) {
//        forn(j,0,m) {
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    vvi x(n, vi(m, 0));
    vi cnt1(m,0);
    vi cnt0(m,0);
    vector<mv> q;
    forn(i,0,n) forn(j,0,m) {
        for(int k = int(a[i][j].size()) - 1; k>=0; k--) {
            if(a[i][j][k] == '0') {
                if(i == n-1 && j==0) {
                    q.pb(mv(i+1,j+1,i+1,j+2));
                    cnt0[1]++;
                }
                else if(i == n-1) {
                    q.pb(mv(i+1,j+1,i+1,1));
                    cnt0[0]++;
                }
                else {
                    q.pb(mv(i+1, j+1, n, j+1));
                    cnt0[j]++;
                }
            }
            else if(a[i][j][k] == '1'){
                if(i == 0 && j==0) {
                    q.pb(mv(i+1,j+1,i+1,j+2));
                    cnt1[1]++;
                }
                else if(i == 0) {
                    q.pb(mv(i+1,j+1,i+1,1));
                    cnt1[0]++;
                }
                else {
                    q.pb(mv(i+1, j+1, 1, j+1));
                    cnt1[j]++;
                }
            }
        }
    }

    vector<mv> q2;
    vi cnt12(m,0);
    vi cnt02(m,0);
    forn(i,0,n) forn(j,0,m) {
//        for(int k = int(b[i][j].size()) - 1; k>=0; k--) {
        forn(k,0,b[i][j].size()) {
            if(b[i][j][k] == '0') {
                if(i == n-1 && j==0) {
                    q2.pb(mv(i+1,j+1,i+1,j+2));
                    cnt02[1]++;
                }
                else if(i == n-1) {
                    q2.pb(mv(i+1,j+1,i+1,1));
                    cnt02[0]++;
                }
                else {
                    q2.pb(mv(i+1, j+1, n, j+1));
                    cnt02[j]++;
                }
            }
            else if(b[i][j][k] == '1'){
                if(i == 0 && j==0) {
                    q2.pb(mv(i+1,j+1,i+1,j+2));
                    cnt12[1]++;
                }
                else if(i == 0) {
                    q2.pb(mv(i+1,j+1,i+1,1));
                    cnt12[0]++;
                }
                else {
                    q2.pb(mv(i+1, j+1, 1, j+1));
                    cnt12[j]++;
                }
            }
        }
    }
    forn(i,0,m) {
        forn(j,0,m) {
            while(cnt1[i] > cnt12[i] && cnt1[j] < cnt12[j]) {
                cnt1[i] --;
                cnt1[j] ++;
                q.pb(mv(1,i+1,1,j+1));
            }
            while(cnt0[i] > cnt02[i] && cnt0[j] < cnt02[j]) {
                cnt0[i] --;
                cnt0[j] ++;
                q.pb(mv(n,i+1,n,j+1));
            }
        }
    }
    reverse(all(q2));
    for(auto x : q2) {
        q.pb(mv(x.x2,x.y2,x.x1,x.y1));
    }
    
//        forn(i,0,n) {
//            forn(j,0,m) {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//        for(auto x : q) {
////            cout<<"MOVE "<<x.x1<<' '<<x.y1<<' '<<x.x2<<' '<<x.y2<<endl;
//            int l = a[x.x1-1][x.y1-1].size();
//            if(l==0) break;
//            char sym = a[x.x1-1][x.y1-1][l-1];
//            a[x.x1-1][x.y1-1].resize(l-1);
//            a[x.x2-1][x.y2-1] = string(1,sym) + a[x.x2-1][x.y2-1];
////            forn(i,0,n) {
////                forn(j,0,m) {
////                    cout<<a[i][j]<<' ';
////                }
////                cout<<endl;
////            }
////            cout<<endl;
//        }
//        forn(i,0,n) {
//            forn(j,0,m) {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<endl;
//        }
    printf("%d\n",q.size());
    for(auto x : q) {
        printf("%d %d %d %d\n", x.x1, x.y1,x.x2,x.y2);
    }
}