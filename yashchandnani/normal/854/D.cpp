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
#define    pq(x)         priority_queue<x,std::vector<x>,compare>
struct compare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi>rhs.fi;
  }
};
std::vector<ii> v1[1000007],v2[1000007];
pq(ii) q[100009];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int m;cin>>m;
  int k;cin>>k;
  int a[n+1]={0};
  rep(i,m){
    int d,arr,dep,cst;
    cin>>d>>dep>>arr>>cst;
    if (arr==0)
    {
      v1[d].pb(mp(dep,cst));
    }
    else{
      if (d<=k)
      {
        continue;
      }
      v2[d].pb(mp(arr,cst));
      q[arr].push(mp(cst,d));
    }
  }
  int poss1=0,poss2=n;
  ll ans=0,mc=1e17;
  repA(i,1,n){
    if (q[i].size()==0)
    {
      cout<<-1<<endl;
      return 0;
    }
    ans+=q[i].top().fi;
  }
  repA(i,1,1000003){
    bool flag=false;
    rep(j,v2[i+k].size()){
      while (q[v2[i+k][j].fi].top().se<=i+k)
      {
        ii trv = q[v2[i+k][j].fi].top();
        ans-=trv.fi;
        q[v2[i+k][j].fi].pop();
        trv = q[v2[i+k][j].fi].top();
        ans+=trv.fi;
        if (q[v2[i+k][j].fi].size()==0)
        {
          flag=true;
          break;
        }
      }
      if (flag)
      {
        break;
      }
    }
    if (flag)
    {
      break;
    }
        rep(j,v1[i].size()){
      if (a[v1[i][j].fi]==0)
      {
        a[v1[i][j].fi]=v1[i][j].se;
        ans+=v1[i][j].se;
        poss1++;
      }
      else if (a[v1[i][j].fi]>v1[i][j].se)
      {
        ans+=v1[i][j].se-a[v1[i][j].fi];
        a[v1[i][j].fi]=v1[i][j].se;
      }
    }
    if (poss1==n)
    {
      mc=min(mc,ans);
    }

  
  }
  if (mc<1e17)
  {
    cout<<mc<<endl;
  }
  else{
    cout<<-1<<endl;
  }

  return 0;
}