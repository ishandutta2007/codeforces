#include<bits/stdc++.h>

const int N = 200010;
const int M = 110;

int min[N];
int sg[N];
std::vector <int> prime;
std::bitset <N> set[M];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (int j = 0, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int main(){
    init();
    int n, f;
    scanf("%d%d", &n, &f);
    std::bitset <N> pos;
    for (int i = 2; i < N; ++ i){
        if (i == f) continue;
        int x = i / min[i];
        if (i == min[i] || x == min[x]){
            pos[i] = 1;
        }
    }
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < M; ++ j){
            if (!set[j][i]){
                sg[i] = j;
                set[j] |= pos << i;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ans ^= sg[y - x - 1] ^ sg[z - y - 1];
    }
    puts(ans ? "Alice\nBob" : "Bob\nAlice");
    return 0;
}