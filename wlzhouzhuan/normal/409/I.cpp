#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;
char str[N];
int f[N], d[N];
int inq;

vector <int> a, adj[N];

void topo() {
  queue <int> q;
  for (int i = 1; i <= 10000; i++)
    if (d[i] == 0) q.push(i), inq++;
  
  while (!q.empty()) {
    int u = q.front(); q.pop();
    //printf("in topo %d\n", u);
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      f[v] = max(f[v], f[u] + 1);
      if (--d[v] == 0) {
        q.push(v); inq++;
      }
    }
  }
  
  /*
  cerr << "debug\n";
  for (int i = 1; i <= 5; i++)
    cerr << f[i] << '\n';
  */
  return ;
}

int main() {
  scanf("%s", str);

  int len = strlen(str), cnt = 0;
  int lst = 0, flag = 0;
  char op;

  for (int i = 0; i < len; i++) {
    //printf("Process (%d): %d %d\n", i, lst, cnt);
    if (str[i] == ':') {
      flag = 1; i++;
      continue;
    }
    
    if (!flag) {
      if (str[i] == '_') cnt++;
      else if (cnt) {
        a.push_back(cnt);
        cnt = 0;
      }
      continue;
    }
    else {
      if (str[i] == '_') cnt++;
      else if (str[i] == '<' || str[i] == '>') {
        lst = cnt; op = str[i];
        cnt = 0;
      }
      else if (op == '<') {
        adj[lst].push_back(cnt);
        d[cnt]++; cnt = 0;
      }
      else {
        adj[cnt].push_back(lst);
        d[lst]++; cnt = 0;
      }
    }
  }
  
  /*
  for (int i = 1; i <= 10; i++) {
    int rev = 0; 
    //assert(d[i] == adj[i].size());
    for (int j = 0; j < adj[i].size(); j++)
      rev |= 1, cerr << adj[i][j] << ' ';
    if (rev) cerr << '\n';
  }
  
  for (int i = 0; i < a.size(); i++)
    cerr << a[i] << ' ';
  */
  
  topo();
  
  int maxnum = *max_element(f + 1, f + N);
  //printf("%d\n", inq);
  if (maxnum > 9 || inq != 10000)
    puts("false");
  else {
    for (int i = 0; i < a.size(); i++)
      printf("%d", f[a[i]]);
    putchar('\n');
  }
  return 0;
}