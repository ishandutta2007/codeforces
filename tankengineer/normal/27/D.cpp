//27D
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, u[105], v[105], fa[505];
char rev, col[505];

int find(const int i) {return i == fa[i] ? i : fa[i] = find(fa[i]);};
void merge(const int i, const int j) {fa[i] = j;}

bool cross(const int i, const int j) {
  bool t1, t2;
  if (u[i] == u[j] || u[i] == v[j] || v[i] == u[j] || v[i] == v[j]) return false;
  t1 = (u[i] < u[j] && u[j] < v[i]);
  t2 = (u[i] < v[j] && v[j] < v[i]);
  return t1 != t2;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u[i], &v[i]);
    if (u[i] > v[i]) {
      swap(u[i], v[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    fa[i] = i; fa[i + m] = i + m;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (cross(i, j)) {
        //wprintf("Cross : (%d %d) (%d %d)\n", u[i], v[i], u[j], v[j]);
        merge(find(i), find(j + m));
        merge(find(i + m), find(j));
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (find(i) == find(i + m)) {
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (col[i] == 0) col[i] = 'i';
    if (col[i] == 'i') rev = 'o'; else rev = 'i';
    for (int j = i + 1; j <= m; j++) {
        if (find(j) == find(i)) col[j] = col[i]; else if (find(j + m) == find(i)) col[j] = rev;
    }
    printf("%c", col[i]);
  }
  puts("");
  return 0;
}