//26B
#include<cstdio>
#include<cstring>

int cnt, ans;
char ch; 

int main() {
    cnt = ans = 0;
    while (1) {
        ch = getchar();
        if (ch  == '(') {
            cnt++;
        } else if (ch == ')'){
            if (cnt > 0) {
                cnt--;
                ans += 2;
            }
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}