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
    int n;
    cin>>n;
    vi a(1000001, 0);
    deque<int> q;
    for(int i=0; i<n; i++) {
        int x;
        char c;
        cin>>c>>x;
        if(c=='+') a[x]=1;
        else {
            if(a[x]==0) q.push_front(x);
            a[x]=0;
            x=-x;            
        }
        q.pb(x);
    }
    int cur=0;
    int maxx=0;
    for(int i=0; i<q.size(); i++) {
        if(q[i]>0) cur++;
        else cur--;
        if(cur>maxx) maxx=cur;
    }
    cout<<maxx;
}