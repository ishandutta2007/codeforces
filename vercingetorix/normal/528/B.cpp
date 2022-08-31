#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

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
    int n, x, w;
    cin >> n;
    set<pair<int,int> > seg;
    for(int i=0; i<n; i++) {
        cin>>x>>w;
        seg.insert(mp(x+w, x-w));
    }
    //sort(all(seg));
    vi ms(n+1,0);
    map<pair<int,int>, int> maxnum;
    auto it = seg.begin();
    for(int i=1; i<=n; i++) {
        int y = (*it).first;
        x = (*it).second;
        if (x==y) {
            ms[i] = ms[i-1] + 1;
            maxnum[mp(x,x)] = ms[i];
        }
        else {
            auto it2 = seg.upper_bound(mp(x,x+1));
            it2--;
            //cout<<i<<"   "<< (*it2).
            int m = max(maxnum[*it2]+1, ms[i-1]);
            maxnum[mp(y,x)] = m;
            ms[i]=m;
        }
        it++;
    }
    cout << ms[n];
}