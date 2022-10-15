#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

std::vector<std::pair<int, int>> v[100007];
std::vector<std::pair<int, int>> odv[100007];
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> kr;

bool odw[100007];
int post[100007];
int mpost[100007];
int zeit = 0;

void dfs(int a, int war) {
    odw[a] = true;
    for (auto it : v[a])
        if (it.second > war && !odw[it.first])
            dfs(it.first, war);
    post[++zeit] = a;
    mpost[a] = zeit;
}

bool check(int a, int war) {
    odw[a] = true;
    for (auto it : odv[a])
        if (war < it.second && !odw[it.first])
            return true;
    return false;
}

int N, M;

bool sprawdz(int war) {
    zeit = 0;
    memset(odw, 0, sizeof(odw));
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i, war);
    memset(odw, 0, sizeof(odw));
    for (int i = zeit; i >= 1; i--)
        if (check(post[i], war))
            return false;
    return true;
}

std::vector<int> wywalam;

int main() {
    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back({b, c});
        odv[b].push_back({a, c});
        kr.push_back({{c, i}, {a, b}});
    }
    int pocz = -1, kon = 1000000001;
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        if (sprawdz(sr))
            kon = sr;
        else
            pocz = sr;
    }
    sprawdz(kon);
    int wyn = kon;
    for (auto it : kr) {
        if (it.first.first <= wyn) {
            if (mpost[it.second.first] < mpost[it.second.second])
                wywalam.push_back(it.first.second);
        }
    }
    printf("%d %d\n", wyn, (int) wywalam.size());
    for (auto it : wywalam) {
        printf("%d ", it);
    }
    printf("\n");
    return 0;
}