#include<cstdio>
#include<cstring>

const int MAXV = 100050, MAXE = 200050;
int adj[MAXE], ptr[MAXV], next[MAXE], col[MAXV], deg[MAXV], sol[MAXV], used[MAXV], pair[MAXV][2];

void dfs(int u, int c)
{
  if(~col[u]) return;
  col[u] = c;
  for(int z=ptr[u]; ~z; z=next[z]) {
    int v = adj[z];
    dfs(v, 1-c);
  }
}

int main()
{
  int n, m, e = 0;
  scanf("%d%d", &n, &m);

  memset(ptr, ~0, sizeof(ptr));
  for(int i=0; i<m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    next[e] = ptr[a]; ptr[a] = e; adj[e] = b; deg[a]++; e++;
    next[e] = ptr[b]; ptr[b] = e; adj[e] = a; deg[b]++; e++;
  }

  memset(col, ~0, sizeof(col));
  for(int i=0; i<n; ++i)
    if(!~col[i]) dfs(i, 0);

  int on = 0;
  for(int i=0; i<n; ++i)
    on += col[i];

  if(on % 3 == 0) {
    puts("YES");
    int zs = 0, os = 0;
    for(int i=0; i<n; ++i) {
      if(col[i] == 0) printf("%d", 1+zs/3+on/3), zs++;
      if(col[i] == 1) printf("%d", 1+os/3), os++;
      putchar(i==n-1 ? '\n' : ' ');
    }
    return 0;
  }

  memset(sol, ~0, sizeof(sol));
  if(on % 3 == 1) {
    for(int i=0; i<n; ++i)
      col[i] = 1-col[i];
    on = n - on;
  }

  for(int i=0; i<n; ++i) {
    if(col[i] == 1) continue;
    if(on - deg[i] >= 2) {
      puts("YES");
      sol[i] = n/3;
      memset(used, ~0, sizeof(used));
      for(int z=ptr[i]; ~z; z=next[z]) used[adj[z]] = 1;
      for(int j=0, k=0; k<2; ++j) {
	if(col[j]==1 && !~used[j]) {
	  sol[j] = n/3;
	  k++;
	}
      }
      int zs = 0, os = 0;
      for(int i=0; i<n; ++i) {
	if(~sol[i]) printf("%d", sol[i]);
	else if(col[i] == 0) printf("%d", 1+zs/3+on/3), zs++;
	else if(col[i] == 1) printf("%d", 1+os/3), os++;
	putchar(i==n-1 ? '\n' : ' ');
      }
      return 0;
    }
  }

  int done = 0, trip = 0;
  memset(used, 0, sizeof(used));
  for(int i=0; i<n; ++i) {
    if(col[i] == 0) continue;
    if((n - on) - deg[i] >= 2) {
      sol[i] = 1 + done / 3;
      done++;
      memset(used, ~0, sizeof(used));
      for(int z=ptr[i]; ~z; z=next[z]) used[adj[z]] = 1;
      for(int j=0, k=0; k<2; ++j) {
	if(col[j]==0 && !~used[j]) {
	  sol[j] = 1 + done / 3;
	  done++; k++;
	}
      }
      trip++;
      if(trip == 2) break;
    }
  }
  if(trip < 2) {
    puts("NO");
    return 0;
  }
  for(int i=0; i<n; ++i) {
    if(col[i]==0 && !~sol[i]) {
      sol[i] = 1 + done / 3;
      done++;
    }
  }
  for(int i=0; i<n; ++i) {
    if(col[i]==1 && !~sol[i]) {
      sol[i] = 1 + done / 3;
      done++;
    }
  }

  puts("YES");
  for(int i=0; i<n; ++i)
    printf("%d%c", sol[i], i==n-1 ? '\n' : ' ');

  return 0;
}