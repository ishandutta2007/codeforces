//22E
#include<cstdio>

int n, call[100005], top, callin[100005], callout[100005], asd[100005], top2;
bool called[100005], vis[100005], recall[100005];

void dfs(const int &i) {
  vis[i] = true;
  if (!vis[call[i]]) dfs(call[i]);
  asd[i] = asd[call[i]];
  if (asd[i] == 0) asd[i] = i;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &call[i]);
    called[call[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  top = 0;
  for (int i = 1; i <= n; i++) {
    if (!called[i]) {
      top++;
      callin[top] = i;
      callout[top] = asd[i];
      recall[asd[i]] = true;
    }
  }
  top2 = top;
  for (int i = 1; i <= n; i++) {
    if (asd[i] == i && !recall[i]) {
      top++;
      callin[top] = callout[top] = i;
    }
  }
  if (top == 1 && top2 == 0) top = 0;
  printf("%d\n", top); 
  for (int i = 1; i <= top; i++) {
    printf("%d %d\n", callout[i], callin[i % top + 1]);
  }
  
  return 0;
}