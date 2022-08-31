#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    //cin >> n>>m;
    scanf("%d %d\n",&n,&m);
    vi a(n);
    vi r(m), t(m);
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    for(int i = 0; i<m; i++) scanf("%d %d", &t[i], &r[i]);
    deque<pair<int,int>> man;
    for(int i =m-1; i>=0; i--) {
        if ((man.size()==0) || (r[i] > man.front().first)) {
            man.push_front(mp(r[i], t[i]));
        }
    }
    deque<int> ans;
    for(int i =n-1; i>=man.front().first; i--) ans.push_front(a[i]);
    deque<int> lo;
    for(int i =0; i<man.front().first; i++) lo.pb(a[i]);
    sort(all(lo));
    man.pb(mp(0, 1));
    while(man.size() > 1) {
        int mode = man[0].second;
        while(lo.size() > man[1].first) {
            if(mode == 1) {
                ans.push_front(lo.back());
                lo.pop_back();
            }
            else {
                ans.push_front(lo[0]);
                lo.pop_front();
            }
        }
        man.pop_front();
    }
    for(auto a:ans) printf("%d ", a);
    
    

}