#include<bits/stdc++.h>

const int N = 200010;

char s[N], t[N];

int main(){
    scanf("%s%s", s, t);
    int n = strlen(s);
    int x = n;
    while (x % 2 == 0){
        x /= 2;
    }
    for (int i = n; i >= x; i >>= 1){
        std::vector <std::vector <std::string>> v1, v2;
        for (int j = 0; j < n / i; ++ j){
            std::vector <std::string> vec1, vec2;
            for (int k = j * i; k < (j + 1) * i; k += x){
                std::string str1, str2;
                for (int u = k; u < k + x; ++ u){
                    str1 += s[u];
                    str2 += t[u];
                }
                vec1.push_back(str1);
                vec2.push_back(str2);
            }
            std::sort(vec1.begin(), vec1.end());
            std::sort(vec2.begin(), vec2.end());
            v1.push_back(vec1);
            v2.push_back(vec2);
        }
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        if (v1 != v2){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}