//1182A
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int l1, l2, cnt, pos[100005];
char s1[100005], s2[100005];

int main() {
  gets(s1); l1 = strlen(s1);
  gets(s2); l2 = strlen(s2);
  if (l1 != l2) {
    puts("NO");
    return 0;
  }
  for (int i = 0; i < l1; i++) {
    if (s1[i] != s2[i]) {
      cnt++; pos[cnt] = i;
    }
  }
  if (cnt != 2) {
    puts("NO");
    return 0;
  }
  if (s1[pos[1]] == s2[pos[2]] && s1[pos[2]] == s2[pos[1]]) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}