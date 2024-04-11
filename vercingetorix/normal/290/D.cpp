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

ll mod=1000000007;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  ll n,m,k,p,t,q;
  
  string s;
  cin>>s;
  cin>>n;
  for(int i=0; i<s.length(); i++){
    if((s[i]>='A')&&(s[i]<='Z')) s[i]+='a'-'A';
  }
  for(int i=0; i<s.length(); i++){
      if(s[i]<'a'+n) s[i]=s[i]+'A'-'a';
  }


  cout<<s;



//cout<<go(40,822);
  return 0;
}