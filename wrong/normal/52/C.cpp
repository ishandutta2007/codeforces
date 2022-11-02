#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

typedef long long ll;

int n, m, k = 450;
ll a[200550], b[500], c[500];

void check(int x)
{
  b[x] = 1LL<<50;
  for(int i=0; i<k && x*k+i<n; ++i)
    b[x] = min(b[x], a[x*k+i]);
}

void add(int l, int r, int v)
{
  for(int i=l; i<=r && i<l/k*k+k; ++i) a[i]+=v;
  check(l/k);
  if(l/k == r/k) return;
  for(int i=l/k+1; i*k+k<=r; ++i) c[i]+=v;
  for(int i=r/k*k; i<=r; ++i) a[i]+=v;
  check(r/k);
}

ll query(int l, int r)
{
  ll res = 1LL<<50;
  for(int i=l; i<=r && i<l/k*k+k; ++i) res = min(res, a[i]+c[i/k]);
  if(l/k == r/k) return res;
  for(int i=l/k+1; i*k+k<=r; ++i) res = min(res, b[i]+c[i]);
  for(int i=r/k*k; i<=r; ++i) res = min(res, a[i]+c[i/k]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<=(n-1)/k; ++i) check(i);

  cin >> m >> ws;
  for(int i=0; i<m; ++i) {
    int l, r, v;
    string s;
    stringstream ss;
    getline(cin, s); ss << s;
    if(ss >> l >> r >> v) {
      if(l <= r) add(l, r, v);
      else add(0, r, v), add(l, n-1, v);
    } else {
      if(l <= r) cout << query(l, r) << endl;
      else cout << min(query(0, r), query(l, n-1)) << endl;
    }
  }

  return 0;
}