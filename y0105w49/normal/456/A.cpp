//begin 20:05

#include <stdio.h>

using namespace std;

int main() {

  int n;
  scanf("%d",&n);

  int a,b;
  for (int i = 0; i<n; i++) {
    scanf("%d %d",&a,&b);
    if (a!=b) {
      printf("Happy Alex\n");
      return 0;
    }
  }

  printf("Poor Alex\n");

  return 0;

}