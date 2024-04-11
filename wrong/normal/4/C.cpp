#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
    int n;
    map<string, int> m;
    char s[36];
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);
        if(m.find(s) == m.end()) {
            puts("OK");
            m[s] = 1;
        } else {
            printf("%s%d", s, m[s]++);
            puts("");
        }
    }
    return 0;
}