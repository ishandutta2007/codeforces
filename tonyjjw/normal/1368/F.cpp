#include<stdio.h>
#include<vector>

using namespace std;

const int MN = 1000 + 1;
int N, K;
bool status[MN];

int main() {
  scanf("%d", &N);
  while(K*K <= N) K++;
  K--;

  while(true) {
    vector<int> lamps;
    for(int i = 0; i < N; i++) {
      if (i % K == 0) continue;
      if (status[i] == false) {
        lamps.push_back(i);
        status[i] = true;
      }
    }
    if (lamps.empty()) {
      puts("0");
      fflush(stdout);
      return 0;
    }

    int n = (int)lamps.size();
    printf("%d", n);
    for(int &lamp: lamps)
      printf(" %d", lamp+1);
    printf("\n");
    fflush(stdout);

    int result;
    scanf("%d", &result); result--;
    int offed = 0;
    for(int i = 0; i < n; i++) {
      if (status[(result+i)%N] == true) {
        status[(result+i)%N] = false;
        offed++;
      }
    }

    if (offed == n) {
      puts("0");
      fflush(stdout);
      return 0;
    }
  }
  return 0;
}