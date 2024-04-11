#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int D[403][401][53];

int main()
{
/*#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif*/
  int n,k;
  cin>>n>>k;
  vi a(n+1);
  a[0]=0;
  int ans=0;
  for(int i=1; i<=n; i++) cin>>a[i];
  vi s(n+1);
  int sum=0;
  for (int i=0; i<=n; i++) {
      sum+=a[i];
      s[i]=sum;
  }
  for(int i=0;i<=n;i++) for(int j=0; j<=n; j++) for(int kk=0; kk<=k; kk++) D[i][j][kk]=-1;
  for (int last = 0; last < n; last++) {
      for (int step = 1; step <= n-last; step++){
          D[last+step][step][1]=0;
      }
  }
  for (int last = 1; last <= n; last++) {
      for (int num = 2; num <= k;num++) {
          for (int prev = 1; prev <= last-num+2; prev++){
              for (int step=1; step<=n-last; step++) {
                  if (num == 1) D[last+step][step][1] = 0;
                  else D[last+step][step][num] = max(D[last+step][step][num], D[last][prev][num-1] + abs(s[last+step]-2*s[last]+s[last-prev]));
              }
              if (num == k) ans= max(ans, D[last][prev][k]);
          }
      }
  }
  

  cout<<ans;



}