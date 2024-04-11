#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> v(n);
  rep(i,0,n) cin>>v[i];
  vector<tuple<int,int,int> > ans;
  auto flip = [&](int x, int y, int z) {
    assert(x < y && y < z && y-x == z-y);
    cerr << x << " " << y << " " << z << endl;
    ans.eb(x+1,y+1,z+1);
    v[x] = 1-v[x];
    v[y] = 1-v[y];
    v[z] = 1-v[z];
  };
  int l = 0, r = n;

  if(n < 17) {
    int M = (1<<n);
    int start = 0;
    rep(i,0,n) start |= (v[i] << i);
    vector<int> dad(M,-1);
    queue<int> q;
    q.emplace(start);
    dad[start] = -2;
    while(!q.empty()) {
      int mask = q.front();
      q.pop();
      rep(i,0,n) rep(j,i+1,n) {
        int k = 2*j-i;
        if(k >= n) break;
        int nmask = mask ^ (1<<i) ^ (1<<j) ^ (1<<k);
        if(dad[nmask] == -1) {
          dad[nmask] = mask;
          q.emplace(nmask);
        }
      }
    }
    for(int cur = 0; dad[cur] >= 0; cur = dad[cur]) {
      int delta = cur ^ dad[cur];
      vi v;
      rep(i,0,n) if((delta>>i)&1) v.eb(i);
      assert(v.size() == 3);
      flip(v[0], v[1], v[2]);
    }
    goto prtAns;
  }

  while(r-l > 15) {
    if(v[l] == 0) { ++l; continue; }
    if(v[r-1] == 0) { --r; continue; }
    if(v[l] == 1 && v[l+1] == 1 && v[l+2] == 1) {
      flip(l,l+1,l+2);
      continue;
    }
    if(v[r-1] == 1 && v[r-2] == 1 && v[r-3] == 1) {
      flip(r-3,r-2,r-1);
      continue;
    }
    if(v[l] == 1 && v[l+1] == 0 && v[l+2] == 1) {
      flip(l,l+2,l+4);
      continue;
    }
    if(v[r-1] == 1 && v[r-2] == 0 && v[r-3] == 1) {
      flip(r-5,r-3,r-1);
      continue;
    }
    if(v[l] == 1 && v[l+1] == 0 && v[l+2] == 0) {
      flip(l,l+3,l+6);
      continue;
    }
    if(v[r-1] == 1 && v[r-2] == 0 && v[r-3] == 0) {
      flip(r-7,r-4,r-1);
      continue;
    }

    assert(v[l] == 1 && v[l+1] == 1 && v[l+2] == 0);
    assert(v[r-1] == 1 && v[r-2] == 1 && v[r-3] == 0);
    if((l+r-1) % 2 == 0) {
      flip(l, (l+r-1)/2, r-1);
      flip(l+1, (l+r-1)/2, r-2);
    }
    else {
      flip(l, (l+r-2)/2, r-2);
      flip(l+1, (l+r)/2, r-1);
    }
  }
  rep(_,0,100){
    rep(a,l,r) rep(b,a+1,r) rep(c,b+1,r) {
      if(b-a == c-b)
        if(v[a] + v[b] + v[c] == 3) flip(a,b,c);
    }
    rep(a,l,r) rep(b,a+1,r) rep(c,b+1,r) {
      if(b-a == c-b)
        if(v[a] + v[b] + v[c] == 2) {
          flip(a,b,c);
          goto done;
        }
    }
done:;
  }
  rep(i,0,n) if(v[i]) {
    if(i >= 6) {
      flip(i-6,i-3,i-0);
      flip(i-6,i-5,i-4);
      flip(i-5,i-4,i-3);
    }
    else if(i+6 < n) {
      flip(i+0,i+3,i+6);
      flip(i+3,i+4,i+5);
      flip(i+4,i+5,i+6);
    }
  }
prtAns:;
  rep(i,0,n) if(v[i]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for(auto f: ans) {
    int a,b,c;
    tie(a,b,c) = f;
    cout << a << " " << b << " " << c << "\n";
  }
  return 0;
}