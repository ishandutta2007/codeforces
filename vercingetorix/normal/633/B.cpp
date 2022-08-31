#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
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
    //ll n,m;
    ll ans = 0;
    int m;
    cin>>m;
    int n  =5;
    m--;
    while (m>0) {
        n+=5;
        int k=n;
        while(k%5==0) {
            m--;
            k/=5;
        }
    }
    if(m<0) {
        cout<<0;
    }
    else {
        cout<<5<<endl;
        cout<<n<<" "<<n+1<<" "<<n+2<<" "<<n+3<<" "<<n+4;
    }
    
    //cout<<ans;
}