#include<bits/stdc++.h>

const int N = 110;

char s[N];

bool ask(int x, int y){
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%s", s);
    if (!strcmp(s, "x")){
        return true;
    }
    if (!strcmp(s, "y")){
        return false;
    }
    if (!strcmp(s, "e")){
        exit(0);
    }
    return false;
}

int main(){
    while (true){
        scanf("%s", s);
        if (!strcmp(s, "end")){
            break;
        }
        int left = -1, right = -1;
        for (int i = 0; i < 29; ++ i){
            bool flag = ask(1 << (i + 1), 1 << i);
            if (!flag){
                left = (1 << i) + 1, right = 1 << (i + 1);
                break;
            }
        }
        if (left == -1){
            if (ask(1, 2)){
                puts("! 1");
                fflush(stdout);
                continue;
            }
            left = (1 << 29) + 1, right = 1e9;
        }
        if (!ask(left, left * 2 - 2)){
            printf("! %d\n", left);
            fflush(stdout);
            continue;
        }
        int ll = left, rr = right;
        ++ left, ++ right;
        while (left < right){
            int mid = (left + right) >> 1;
            if (ask(ll, mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        if (left == rr + 1){
            left = ll;
        }
        printf("! %d\n", left);
        fflush(stdout);
    }
    return 0;
}