#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
//#include <unordered_map>
#include <map>
#include <list>
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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin >> n;
    vi p(n);
    ll ans=0;
    vi d(n,0);
    vi dir(n, 0);
    vb u(n,false);
    vector<pair<int, int> > s;
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        p[i]=x;
        s.pb(mp(abs(x),i));
    }
    sort(all(s));
    for(int i=n-1; i>=0; i--) {
        int invu = 0, invd = 0;
        int pos = s[i].second;
        u[pos]=true;
        for(int j=pos+1; j<n; j++) {
            if(!u[j]) invu++;
        }
        for(int j=0; j<pos; j++) {
            if((!u[j])&&(abs(p[j])!=s[i].first)) invd++;
        }
        ans+=min(invd,invu);
    }
    cout<<ans;
    
}