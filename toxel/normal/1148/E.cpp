#include <bits/stdc++.h>

const int N = 300010;
typedef std::pair <int, int> pii;
typedef std::pair <pii, int> piii;
typedef long long ll;

int s[N], t[N];
int id[N];
pii p[N];
std::vector <piii> ans;

void print(int id1, int id2, int dis){
    ans.push_back({{id1, id2}, dis});
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &s[i]);
        p[i] = {s[i], i};
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &t[i]);
    }
    std::sort(p, p + n);
    std::sort(t, t + n);
    for (int i = 0; i < n; ++ i){
        s[i] = p[i].first;
        id[i] = p[i].second;
    }
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++ i){
        sum1 += s[i];
        sum2 += t[i];
    }
    if (sum1 != sum2){
        puts("NO");
        return 0;
    }
    for (int i = 0, j = 0; i < n; ++ i){
        if (s[i] > t[i]){
            puts("NO");
            return 0;
        }
        if (s[i] == t[i]){
            continue;
        }
        while (s[i] < t[i]){
            while (s[j] <= t[j]){
                ++ j;
            }
            int dis = std::min(s[j] - t[j], t[i] - s[i]);
            print(id[i], id[j], dis);
            s[i] += dis;
            s[j] -= dis;
        }
    }
    puts("YES");
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d %d %d\n", u.first.first + 1, u.first.second + 1, u.second);
    }
    return 0;
}