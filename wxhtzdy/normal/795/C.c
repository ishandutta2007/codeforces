#include <stdio.h>
 
int main() {
  int n;
  scanf("%i", &n);
  if (n == 1) {
    printf("1");
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      printf("1");
    }
  } else {
    printf("7");
    for (int i = 0; i < n / 2 - 1; i++) {
      printf("1");
    }
  }  
}