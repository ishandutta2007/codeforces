#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m, p;
char s[200010][61];
//bitset<200010>msk[61];
LL bs[200010];
LL ans = 0;
int bm[200010];
int sum[200010];
std::mt19937 rnd(233);

int main() {
    scanf("%d%d%d",&n,&m,&p);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                //msk[j].set(i);
                bs[i] ^= (1LL << j);
            }
        }
    }
    srand(19260817);
    uniform_int_distribution<int> dist(0, 1000000000);
    for (int Test = 1; Test <= 22; Test++) {
        //LL want = bs[rand() % n];
        LL want = bs[dist(rnd) % n];
        vector<int>id;
        for (int i = 0; i < m; i++) {
            if ((want >> i) & 1) {
                id.push_back(i);
            }
        }
        int B = id.size();
        //printf("?? %lld %d\n",want,B);
        for (int i = 0; i < (1 << B); i++) sum[i] = 0;
        //printf("calc %lld\n",want);
        for (int i = 0; i < n; i++) {
            bm[i] = 0;
            for (int j = 0; j < B; j++) {
                if (s[i][id[j]] == '1') {
                    bm[i] |= (1 << j);
                }
            }
            //printf("bm[%d]=%d\n",i,bm[i]);
            sum[bm[i]]++;
        }
        for (int dim = 0; dim < B; dim++) {
            for (int i = (1 << B) - 1; i >= 0 ; i--) {
                if (((i >> dim) & 1) == 0) {
                    sum[i] += sum[i ^ (1 << dim)];
                }
            }
        }
        for (int i = 0; i < (1 << B); i++) {
            //printf("%lld %d %d\n",want,i,sum[i]);
            if (sum[i] >= (n + 1) / 2 && __builtin_popcount(i) > __builtin_popcountll(ans)) {
                //printf("wow %d\n",i);
                ans = 0;
                for (int j = 0; j < B; j++) {
                    if ((i >> j) & 1) {
                        ans |= (1LL << (id[j]));
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d",(ans >> i) & 1);
    }
}