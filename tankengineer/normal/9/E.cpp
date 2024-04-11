//CF 9E
/*
n<=50
 

1    NO kk-1 2
2  

3 
*/

#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, fa[55], size[55], t1, t2, dgr[55], cycle;

int find(const int i) {return (fa[i] == i) ? i : fa[i] = find(fa[i]);};

void merges(const int i, const int j) {
  if (i == j) return ;
  if (size[i] >= size[j]) {
    size[i] += size[j];
    fa[j] = i;
  } else {
    size[j] += size[i];
    fa[i] = j;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    size[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t1, &t2);
    if (find(t1) == find(t2)) cycle++;
    merges(find(t1), find(t2));
    dgr[t1]++; dgr[t2]++;
  }
  if (*max_element(&dgr[1], &dgr[n + 1]) > 2 || cycle > 1 || cycle == 1 && m != n) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n%d\n", n - m);
  while (m < n) {
    if (m + 1 == n) {
      t1 = min_element(&dgr[1], &dgr[n + 1]) - dgr;
      if (n == 1) {
        t2 = t1;
      } else {
        t2 = min_element(&dgr[t1 + 1], &dgr[n + 1]) - dgr;
      }
      printf("%d %d\n", t1, t2); 
    } else {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (find(i) != find(j) && dgr[i] < 2 && dgr[j] < 2) {
            merges(find(i), find(j));
            dgr[i]++; dgr[j]++;
            printf("%d %d\n", i, j);
          }
        }
      } 
    }
    m++;
  }
  
  return 0;
}