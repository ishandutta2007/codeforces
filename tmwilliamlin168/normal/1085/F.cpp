# include <bits/stdc++.h>

# define y1 aasjdladljskdj
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(4e5) + 5;
const int inf = (int)1e9 + 7;

struct bit{
  int t[N];
  void inc(int pos, int val){
    for(; pos < N; pos += pos & -pos){
      t[pos] += val;
    }
  }
  int get(int pos){
    int ans = 0;
    for(; pos > 0; pos -= pos & -pos){
      ans += t[pos];
    }
    return ans;
  }
}s[4];

int n, q;
int l[4], w[4];
char a[N];
set < int > pos[4];

int get(char x){
  return (x == 'R' ? 1 : (x == 'P' ? 2 : 3));
}

pii intersect(pii a, pii b){
  return make_pair(max(a.first, b.first), min(a.second, b.second));
}

int calc(){
  int ans = 0;
  for(int t = 1; t <= 3; ++t){
    if(pos[l[t]].empty()){
      ans += sz(pos[t]);
      continue;
    }
    if(pos[w[t]].empty()){
      continue;
    }
    vector < pii > pf, sf;
    int F = *pos[l[t]].begin();
    int S = *pos[w[t]].begin();
    pii TF = make_pair(-1, -1);
    if(F < S){
      TF = make_pair(F, S - 1);
    }
    pii TS = make_pair(-1, -1);
    F = *pos[l[t]].rbegin();
    S = *pos[w[t]].rbegin();
    if(F > S){
      TS = make_pair(S + 1, F);
    }
    int cur = s[t].get(n);
    if(TF.first != -1){
      cur -= s[t].get(TF.second) - s[t].get(TF.first - 1);
    }
    if(TS.first != -1){
      cur -= s[t].get(TS.second) - s[t].get(TS.first - 1);
    }
    if(TF.first != -1 && TS.first != -1){
      pii q = intersect(TF, TS);
      if(q.first <= q.second){
        cur += s[t].get(q.second) - s[t].get(q.first - 1);
      }
    }
    ans += cur;
  }
  return ans;
}

int main(){
  l[1] = 2, w[1] = 3;
  l[2] = 3, w[2] = 1;
  l[3] = 1, w[3] = 2;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf(" %c", a + i);
    pos[get(a[i])].insert(i);
    s[get(a[i])].inc(i, 1);
  }
  printf("%d\n", calc());
  for(int i = 1; i <= q; ++i){
    int p;
    char x;
    scanf("%d %c", &p, &x);
    pos[get(a[p])].erase(p);
    s[get(a[p])].inc(p, -1);
    a[p] = x;
    pos[get(a[p])].insert(p);
    s[get(a[p])].inc(p, 1);
    printf("%d\n", calc());
  }


  return 0;
}