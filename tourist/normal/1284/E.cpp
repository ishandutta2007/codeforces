/**
 *    author:  tourist
 *    created: 04.01.2020 15:39:58       
**/
// https://codeforces.com/contest/592/submission/13997162
#include <bits/stdc++.h>
 
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
 
using namespace std;
 
 
inline bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if((b.second<0)^(a.second<0))
        return 1LL*a.first*b.second>1LL*b.first*a.second;
    return 1LL*a.first*b.second<1LL*b.first*a.second;
}
 
inline bool eq(const pair<int, int>& a, const pair<int, int>& b)
{
    return 1LL*a.first*b.second==1LL*b.first*a.second;
}

long long Count(vector<pair<int, int>> A) {
    int N = (int) A.size();
/*    scan(N); scan(C); scan(D);
    for(int i=0; i<N; i++)
    {
        scan(A[i].first); scan(A[i].second);
        A[i].first-=C, A[i].second-=D;
    }*/
    sort(A.begin(), A.end(), cmp);
    long long Z=0, ZO=0, ZOZ=0, O=0, OZ=0, OZO=0;
    for(int i=0, j; i<N; i=j)
    {
        long long NZ=Z, NZO=ZO, NZOZ=ZOZ, NO=O, NOZ=OZ, NOZO=OZO;
        for(j=i; j<N && eq(A[i], A[j]); j++)
        {
            if(A[j].second<0)
            {
                NOZO+=OZ;
                NZO+=Z;
                NO++;
            }
            else
            {
                NZOZ+=ZO;
                NOZ+=O;
                NZ++;
            }
        }
        Z=NZ, ZO=NZO, ZOZ=NZOZ, O=NO, OZ=NOZ, OZO=NOZO;
    }
    int L=0, R=0, D=0;
    for(int i=0; i<N; i++) if(A[i].second==0)
    {
        if(A[i].first<0)
            L++;
        else
            R++;
    }
    for(int i=0; i<N; i++) if(A[i].second<0)
        D++;
    return OZO+ZOZ-1LL*L*R*D;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> a;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        a.emplace_back(x[j] - x[i], y[j] - y[i]);
      }
    }
    ans += Count(a);
  }
  cout << ans * (n - 4) / 2 << '\n';
  return 0;
}