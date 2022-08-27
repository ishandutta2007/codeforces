#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include<deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int m,n,k;
  cin>>m>>n;
  vi a(m);
  vi b(n);
  ull suma=0;
  ull sumb=0;
  for(int i=0; i<m; i++){
	  cin>>a[i];
	  suma+=a[i];
  }
  for(int i=0; i<n; i++){
	  cin>>b[i];
	  sumb+=b[i];
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  ull ans=18446744073709551000;

  ull curans=sumb;
  for(int i=0; i<m-1; i++){
	  curans+=min((ull)a[i],sumb);
  }
  if(curans<ans) ans=curans;
  curans=suma;
  for(int i=0; i<n-1; i++){
	  curans+=min((ull)b[i],suma);
  }
  if(curans<ans) ans=curans;
  cout<<ans;

  return 0;

}