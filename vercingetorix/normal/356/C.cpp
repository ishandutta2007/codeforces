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
    int n;
    vi cnt(5,0);
    scanf("%d", &n);
    int tot =0;
    forn(i,0,n) {
        int x;
        
        scanf("%d", &x);
        tot +=x;
        cnt[x]++;
    }
    int ans =0;
    if(tot<3 || tot == 5) {
        cout<<-1;
        return 0;
    }
    while(cnt[1] && cnt[2]) {
        cnt[1]--;
        cnt[2]--;
        cnt[3]++;
        ans++;
    }
    while(cnt[1] > 2) {
        cnt[1]-=3;
        cnt[3]++;
        ans+=2;
    }
    while(cnt[2] > 2) {
        cnt[2]-=3;
        cnt[3]+=2;
        ans+=2;
    }
    if(cnt[1] == 0) {
        if(cnt[2] == 1) {
            if(cnt[4]>0) ans++;
            else ans+=2;
        }
        else if(cnt[2] == 2) ans+=2;
    }
    if(cnt[2]==0) {
        if(cnt[1] == 1) {
            if(cnt[3]>0) ans++;
            else ans+=2;
        }
        else if(cnt[1] == 2)  ans+=2;
    }
    cout<<ans;
}