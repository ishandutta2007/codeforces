using namespace std;
#include <cstdio>
#include <queue>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define mp make_pair
#define fi first
#define se second

int n, cnt;
int a[105], b[105];
bool opened[105];

int main() {
    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d%d", &a[i], &b[i]);
    fto(i, 0, n-1)
        fto(j, 0, n-1)
            if (i!=j && b[i]==a[j] && !opened[j]) {
                ++cnt;
                opened[j] = true;
            }

    printf("%d", n-cnt);
}