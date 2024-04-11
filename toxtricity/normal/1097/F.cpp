#include<bits/stdc++.h>

const int N = 7010;
const int M = 100010;
const int K = 1000010;

std::bitset <N> set[M];
std::bitset <N> factset[N], muset[N];
char ans[K];

int mu[N], min[N];
std::vector <int> prime;

void init(){
    mu[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            mu[i] = 1;
            prime.push_back(i);
        }
        for (int j = 0, k, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
            mu[k] = mu[i];
        }
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            factset[j][i] = 1;
        }
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            if (mu[j / i]){
                muset[i][j] = 1;
            }
        }
    }
}

int main(){
    init();
    int n, q;
    scanf("%d%d", &n, &q);
    int cnt = 0;
    for (int i = 0; i < q; ++ i){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int x, v;
            scanf("%d%d", &x, &v);
            set[x] = factset[v];
        }
        else if (type == 2){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            set[x] = set[y] ^ set[z];
        }
        else if (type == 3){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            set[x] = set[y] & set[z];
        }
        else if (type == 4){
            int x, v;
            scanf("%d%d", &x, &v);
            ans[cnt ++] = ((set[x] & muset[v]).count() & 1) + '0';
        }
    }
    puts(ans);
    return 0;
}