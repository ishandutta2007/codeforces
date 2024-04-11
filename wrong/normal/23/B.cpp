#include<cstdio>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for(int i=0; i<T; ++i) {
    int N;
    scanf("%d", &N);
    printf("%d\n", N>=2 ? N-2 : 0);
  }
  return 0;
}