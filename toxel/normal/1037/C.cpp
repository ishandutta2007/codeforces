#include<bits/stdc++.h>

const int N = 1000010;

char s[N], t[N];

int main(){
    int n;
    scanf("%d%s%s", &n, s, t);
    int cost = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] != t[i]){
            if (i < n - 1 && s[i + 1] != t[i + 1]){
                std::swap(s[i], s[i + 1]);
                ++ cost;
            }
            else{
                ++ cost;
            }
        }
    }
    printf("%d\n", cost);
}