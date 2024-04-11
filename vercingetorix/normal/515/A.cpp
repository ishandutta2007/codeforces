#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvint;

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
  
  ll a,b,s,n,c,m,k,p,t,q,x,y;
  
 
  cin>>a>>b>>s;
  a=abs(a);
  b=abs(b);

  cout << (((a+b<=s)&&((s-a-b)%2==0)) ? "Yes" : "No");



//cout<<go(40,822);
  return 0;
}