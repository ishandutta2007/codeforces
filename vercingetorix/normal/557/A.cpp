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
    int min1,min2,min3,max1,max2,max3,n;
    cin>>n;
    cin>>min1>>max1;
    cin>>min2>>max2;
    cin>>min3>>max3;
    //for(int i=0; i<n; i++) 
    int m1,m2,m3;
    m1=min(max1,n-min2-min3);
    n-=m1;
    m2=min(max2, n-min3);
    m3=n-m2;
    cout<<m1<<' '<<m2<<' '<<m3;
}