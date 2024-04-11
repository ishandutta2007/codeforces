#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

const long long mod = 1000000007;

int main()
{
/*#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif*/
    long long n, m;
    int ans=0;
    cin>>n>>m;
    m--;
    std::deque<int> l;
    l.pb(n);
    for(int i=n-1; i>=1; i--) {
        if(m%2==1) l.pb(i);
        else l.push_front(i);
        m/=2;
    }
    for(auto it=l.begin(); it!=l.end(); it++) cout<<*it<<" ";

    return 0;
}