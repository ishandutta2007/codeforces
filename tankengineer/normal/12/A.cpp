//12A
#include<cstdio>
#include<cstring>

char s1[5], s2[5], s3[5];

int main() {
  scanf("%s%s%s", &s1, &s2, &s3);
  if (s1[0] == s3[2] && s1[1] == s3[1] && s1[2] == s3[0] && s2[0] == s2[2]) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}