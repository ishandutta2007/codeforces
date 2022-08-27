#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k,a,m;
    cin>>n>>k>>a;
    set<int> breaks;
    breaks.insert(0);
    breaks.insert(n+1);
    cin>>m;
    int x;
    int curships;
    curships = (n+1)/(a+1);
    for(int i=0; i<m; i++) {
        cin>>x;
        auto it=breaks.lower_bound(x);
        auto it2=it;
        it2--;
        int l=*it2;
        int r=*it;
        curships-=(r-l)/(a+1);
        curships+=(x-l)/(a+1);
        curships+=(r-x)/(a+1);
        if(curships<k) {
            cout<<i+1;
            return 0;
        }
        breaks.insert(x);
    }
    cout<<-1;
    
}