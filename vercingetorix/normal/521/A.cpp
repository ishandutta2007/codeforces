#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

ll mod=1000000007;
int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

long long n;
cin>>n;
map<char, int> ci;
ci['A'] = 0;
ci['C'] = 1;
ci['G'] = 2;
ci['T'] = 3;
char a[4] = {'A', 'C', 'G', 'T'};
vi num(4,0);
char c;
for(int i=0; i<n; i++) {
    cin>>c;
    num[ci[c]]++;
}
ll ans =0;
int maxx=max(max(num[0], num[1]), max(num[2], num[3]));
for(int i=0; i<4; i++) if(num[i]==maxx) ans++;
ll x = 1;
for(int i=0; i<n; i++) {
    x= (x*ans)%mod;
}

cout<<x;

return 0;
}