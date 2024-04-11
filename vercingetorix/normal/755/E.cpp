#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    cin>>n>>k;
    if(k>3 || k == 1) {
        cout<<-1;
        return 0;
    }
    if(k==2) {
        if(n<5) {
            cout<<-1;
            return 0;
        }
        else {
            printf("%d\n", n-1);
            forn(i,1,n) {
                printf("%d %d\n", i,i+1);
            }
            return 0;
        }
    }
    if(k==3) {
        if(n<4) {
            cout<<-1;
            return 0;
        }
        else if(n==4) {
            printf("%d\n", n-1);
            forn(i,1,n) {
                printf("%d %d\n", i,i+1);
            }
            return 0;
        }
        else {
            printf("%d\n", n-1);
            printf("1 2\n");
            printf("2 3\n");
            forn(i,4,n+1) printf("3 %d\n", i);
            return 0;
        }
    }
}