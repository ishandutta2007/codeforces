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
    int n,m,k;
    ll ans = 0;
    string s;
    cin >> n;
vi a(5,0);
int x;
for(int i =0; i<n; i++){
cin>>x; a[x]++;
}
    ans+=a[4];
ans+=a[3];
a[1]=max(0, a[1]-a[3]);
ans+=a[2]/2;
a[2]=a[2]%2;
if(a[2]) {ans++;
a[1]=max(0, a[1]-2);}
ans+=(a[1]+3)/4;
    
    
    cout<<ans;
}