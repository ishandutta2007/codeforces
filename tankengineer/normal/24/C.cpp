//24C
#include<cstdio>
#include<complex>

using namespace std;

typedef complex<int> point; 
#define x real()
#define y imag()

int n, p, q;
long long m;
point s, a[200005], sum;

int main() {
    scanf("%d %I64d %d %d", &n, &m, &s.x, &s.y);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
    }
    n *= 2;
    p = m % n;
    for (int i = 1; i <= p; i++) {
    s = 2 * a[i] - s;
    }

    printf("%d %d\n", s.x, s.y);
    
  return 0;
}