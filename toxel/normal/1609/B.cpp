 #include <bits/stdc++.h>

const int N = 100010;

char input[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", input);
    std::string str = input;
    std::map <std::string, int> map;
    for (int i = 0; i < n - 2; ++ i){
        map[str.substr(i, 3)] += 1;
    }
    while (q --){
        int pos;
        char ch[10];
        scanf("%d%s", &pos, ch);
        -- pos;
        for (int i = pos - 2; i <= pos; ++ i){
            if (i < 0){
                continue;
            }
            if (i >= n - 2){
                continue;
            }
            map[str.substr(i, 3)] -= 1;
        }

        str[pos] = ch[0];

        for (int i = pos - 2; i <= pos; ++ i){
            if (i < 0){
                continue;
            }
            if (i >= n - 2){
                continue;
            }
            map[str.substr(i, 3)] += 1;
        }
        printf("%d\n", map["abc"]);
    }
    return 0;
}