#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, c[200], done[200];
int adj[200][200], rem[200];

bool proc(int cur)
{
  bool cont = true;
  while(cont) {
    cont = false;
    for(int i=0; i<n; ++i) {
      if(done[i] == 0 && c[i] == cur && rem[i] == 0) {
        done[i] = 1;
        for(int j=0; j<n; ++j)
          if(adj[j][i])
            rem[j]--;
        cont = true;
      }
    }
  }
  
  bool ok = true;
  for(int i=0; i<n; ++i)
    ok &= done[i] == 1;
  return ok;
}

int doit(int f)
{
  int res = 0;
  memset(done, 0, sizeof(done));
  memset(rem, 0, sizeof(rem));
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      rem[i] += adj[i][j];
  while(!proc(f)) {
    res++;
    f = (f+1) % 3;
  }
  return res;
}

int main()
{
  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> c[i];
    c[i]--;
  }
  
  for(int i=0; i<n; ++i) {
    int k;
    cin >> k;
    for(int j=0; j<k; ++j) {
      int a;
      cin >> a;
      adj[i][a-1] = 1;
    }
  }
  
  int res = doit(0);
  res = min(res, doit(1));
  res = min(res, doit(2));
  
  cout << res + n << endl;
  return 0;
}