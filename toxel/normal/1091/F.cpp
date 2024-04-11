#include<bits/stdc++.h>

const int N = 100010;
const int M = 10;
typedef long long ll;

struct event{
    int id;
    ll value;

    event():id(0), value(0){}
    event(int id, ll value):id(id), value(value){}

    bool operator <(const event &e)const{
        return id < e.id;
    }
};

std::vector <event> vec[M];
int sit[M];
ll l[N];
char s[N];

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &l[i]);
    }
    scanf("%s", s);
    bool haswater = false;
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == 'G'){
            vec[2].push_back({i, 0});
            ans += 5 * l[i];
        }
        else if (s[i] == 'W'){
            haswater = true;
            vec[1].push_back({i, 0});
            ans += 3 * l[i];
        }
        else{
            vec[(haswater ? 3 : 5)].push_back({i, l[i]});
            ans += (haswater ? 4 : 6) * l[i];
        }
    }
    for (int i = 0; i < M; ++ i){
        sit[i] = (int) vec[i].size() - 1;
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == 'L') continue;
        ll begin = l[i];
        for (int j = M - 1; j >= 0; -- j){
            if ((s[i] == 'G' && j == 2) || (s[i] == 'W' && j == 1)){
                ans -= l[i] * (s[i] == 'G' ? 2 : 1);
                auto &vec2 = vec[s[i] == 'G' ? 2 : 1];
                auto it2 = std::lower_bound(vec2.begin(), vec2.end(), event(i, 0));
                it2 -> value = (begin - l[i]) * 2 + l[i];
                l[i] = 0;
            }
            while (l[i] && sit[j] >= 0 && vec[j][sit[j]].id > i){
                event &e = vec[j][sit[j]];
                ll x = std::min(l[i], e.value);
                ans -= j * x;
                l[i] -= x;
                e.value -= x;
                if (!e.value){
                    -- sit[j];
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}