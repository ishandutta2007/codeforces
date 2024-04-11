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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int k;cin>>k;
  int a[n];
  int ans[n];
  int flag=0;
  if (k>=n)
  {
    flag=k;
    k=n-1;
    
  }
  priority_queue<ii> q;
  rep(i,k+1) {
    cin>>a[i];
    q.push(mp(a[i],i));
  }
  rep(i,n-k-1){
    cin>>a[i+k+1];
  }
 
  rep(i,n){
    ii z = q.top();
    ans[z.se]=i;
    q.pop();

    if (i+q.size()<n-1)
    {
      q.push(mp(a[k+1+i],k+1+i));
    }
      }
  if (flag!=0)
  {
    k=flag;
  }
  ll cost=0;
  rep(i,n){
    cost+=1LL*(k+ans[i]-i)*a[i];
  }
  cout<<cost<<endl;
  rep(i,n){
    cout<<ans[i]+k+1<<" ";
  }


  return 0;
}