#include<bits/stdc++.h>

const int N = 100010;

std::string str[N];
char s[N];
int type[N];
int cnt[2];
bool vis[N];
int n;
std::vector <std::string> ans;

void print(){
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%s", u.c_str());
    }
}

int trans(std::string s){
    if (s[0] < '1' || s[0] > '9'){
        return -1;
    }
    for (auto u : s){
        if (u < '0' || u > '9'){
            return -1;
        }
    }
    int x = atoi(s.c_str());
    return x <= n ? x : -1;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s%d", s, &type[i]);
        str[i] = s;
        ++ cnt[type[i]];
    }
    std::set <std::string> zero, one, two, three;
    for (int i = 0; i < n; ++ i){
        int x = trans(str[i]);
        if (x == -1){
            (type[i] == 0 ? two : three).insert(str[i]);
            continue;
        }
        vis[x] = true;
        if (x <= cnt[1] && type[i] == 0){
            one.insert(str[i]);
        }
        if (x > cnt[1] && type[i] == 1){
            zero.insert(str[i]);
        }
    }
    std::set <int> zeroempty, oneempty;
    for (int i = 1; i <= cnt[1]; ++ i){
        if (!vis[i]){
            oneempty.insert(i);
        }
    }
    for (int i = cnt[1] + 1; i <= n; ++ i){
        if (!vis[i]){
            zeroempty.insert(i);
        }
    }
    if (zeroempty.empty() && oneempty.empty() && one.empty() && two.empty()){
        puts("0");
        return 0;
    }
    if (zeroempty.empty() && oneempty.empty()){
        for (int i = 100001; i < 1000000; ++ i){
            sprintf(::s, "%d", i);
            std::string s = ::s;
            if (!two.count(s)){
                sprintf(::s, "move %s %d\n", zero.begin() -> c_str(), i);
                ans.push_back(::s);
                zeroempty.insert(trans(*(zero.begin())));
                zero.erase(zero.begin());
                three.insert(s);
                break;
            }
        }
    }
    while ((!zeroempty.empty() || !oneempty.empty()) && (!zero.empty() || !one.empty())){
        while (!zeroempty.empty() && !one.empty()){
            std::string x = *(one.begin());
            int y = *(zeroempty.begin());
            sprintf(s, "move %s %d\n", x.c_str(), y);
            ans.push_back(s);
            oneempty.insert(trans(*(one.begin())));
            one.erase(one.begin());
            zeroempty.erase(zeroempty.begin());
        }
        while (!oneempty.empty() && !zero.empty()){
            std::string x = *(zero.begin());
            int y = *(oneempty.begin());
            sprintf(s, "move %s %d\n", x.c_str(), y);
            ans.push_back(s);
            zeroempty.insert(trans(*(zero.begin())));
            zero.erase(zero.begin());
            oneempty.erase(oneempty.begin());
        }
    }
    while (!zeroempty.empty()){
        std::string x = *(two.begin());
        int y = *(zeroempty.begin());
        sprintf(s, "move %s %d\n", x.c_str(), y);
        ans.push_back(s);
        two.erase(two.begin());
        zeroempty.erase(zeroempty.begin());
    }
    while (!oneempty.empty()){
        std::string x = *(three.begin());
        int y = *(oneempty.begin());
        sprintf(s, "move %s %d\n", x.c_str(), y);
        ans.push_back(s);
        three.erase(three.begin());
        oneempty.erase(oneempty.begin());
    }
    print();
    return 0;
}