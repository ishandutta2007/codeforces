#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

std::vector<ii> v[200000],v2[200000];
std::vector<int> v3[800000];
int start[800000];
ii ans[200000];

int main()
{
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;cin>>n;
  int a[n+3],b[n+3],c[n+3],d[n+3],e[n+3];
  ld f[n];
  bool chk[n]={false};
  rep(i,n){
    cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];


  }
  int ans =n;
  rep(i,n){
    rep(j,n){
      rep(k,j){
        if (j==i||k==i||k==j)
        {
         continue;
        }
        ll ax = (a[i]-a[j])*(a[i]-a[k]);
        ax+= (b[i]-b[j])*(b[i]-b[k]);
        ax+= (c[i]-c[j])*(c[i]-c[k]);
        ax+= (d[i]-d[j])*(d[i]-d[k]);
        ax+= (e[i]-e[j])*(e[i]-e[k]);
        if (ax>0)
        {
          chk[i]=true;
          ans--;
        }
        if (chk[i])
        {
          break;
        }
      }
      if (chk[i])
      {
        break;
      }

    }

  }
  cout<<ans<<"\n";
  rep(i,n){
    if (chk[i]==false)
    {
      cout<<i+1<<"\n";
    }
  }
  return 0;
}