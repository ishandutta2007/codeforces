#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 1e5 + 1;

int N;
int A[MN];
pii fst_snd[2*MN];
int card[2*MN];

void relax(int p, int c) {
    if (fst_snd[p].fst > c)
        fst_snd[p] = pii(c, fst_snd[p].fst);
    else if (fst_snd[p].snd > c)
        fst_snd[p].snd = c;
}

int main() {
    for(auto &v: fst_snd)
        v = pii(1e9, 1e9);

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        int a = A[i];
        for(int p = 2; p * p <= a; p++) {
            if (a % p == 0) {
                int cnt = 0;
                while (a % p == 0) {
                    a /= p;
                    cnt++;
                }
                relax(p, cnt);
                card[p]++;
            }
        }
        if (a > 1) {
            relax(a, 1);
            card[a]++;
        }
    }
    
    ll ans = 1;
    for(int i = 2; i < 2*MN; i++) {
        if(card[i] == N) {
            for(int j = 0; j < fst_snd[i].snd; j++)
                ans *= i;
        }
        else if (card[i] == N-1) {
            for (int j = 0; j < fst_snd[i].fst; j++)
                ans *= i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}