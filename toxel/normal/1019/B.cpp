#include<bits/stdc++.h>

const int N = 100010;

int ask(int sit){
    printf("? %d\n", sit);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

inline int sig(int n){return (n > 0) - (n < 0);}

int main(){
    int n;
    scanf("%d", &n);
    if (n >> 1 & 1){
        puts("! -1");
        return 0;
    }
    int left = 1, right = (n >> 1) + 1;
    int vl = ask(left) - ask(right);
    if (!vl){
        puts("! 1");
        return 0;
    }
    while (true){
        int mid = left + right >> 1;
        int x = ask(mid) - ask((n >> 1) + mid);
        if (!x){
            printf("! %d\n", mid);
            return 0;
        }
        if (sig(x) == sig(vl)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
}