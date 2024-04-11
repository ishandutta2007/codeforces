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
    cin>>n;
    int a,b,c;
    cout<<"? 1 2\n";
    cout.flush();
    cin>>a;
    cout<<"? 2 3\n";
    cout.flush();
    cin>>b;
    cout<<"? 1 3\n";
    cout.flush();
    cin>>c;
    vi ans(n+1);
    ans[1] = (a+c-b)/2;
    ans[2] = (a-c+b)/2;
    ans[3] = (c+b-a)/2;
    forn(i,4,n+1) {
        cout<<"? 1 " << i << endl;
        cout.flush();
        int x;
        cin>>x;
        ans[i] = x- ans[1];
    }
    cout<<"!";
    forn(i,1,n+1) cout<<" "<<ans[i];
    cout<<endl;
    cout.flush();
    
}