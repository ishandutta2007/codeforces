#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <cstring>
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 1001 * 1001;
int dig[N];
int fir[N];
char sl[N];
int lucky[] = {1, 6, 8, 9};
int perm[] = {1, 6, 8, 9};
bool check(int n) {
  int res = 0;
  int pot = 1;
  for (int i = n; i >= 1; i--) {
    res += dig[i] * pot;
    res %= 7;
    pot *= 10;
    pot %= 7;
  }
  return res == 0;
}
int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	scanf("%s", sl + 1);
  int n = strlen(sl + 1);
  for (int i = 1; i <= n; i++) {
    dig[i] = int(sl[i]) - int('0');
  }
  
  for (int i = n; i >= 1; i--) {
    fir[dig[i]] = i;
  }
  
  do {
    for (int i = 0; i < 4; i++) {
      dig[fir[lucky[i]]] = perm[i];
    }
    if (check(n)) {
      for (int i = 1; i <= n; i++) {
        cout<<dig[i];
      }
      cout<<endl;
      return 0;
    }
  } while (next_permutation(perm, perm + 4));
  
  while (next_permutation(dig + 1, dig + n + 1)) {
    if (check(n)) {
      for (int i = 1; i <= n; i++) {
        cout<<dig[i];
      }
      cout<<endl;
      return 0;
    }
  }
  
  
	
	// nie zapomnij o ll
	return 0;
}