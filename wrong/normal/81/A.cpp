#include<cstdio>
#include<cstring>
#include<list>

using namespace std;

char s[200050];
int main()
{
    scanf("%s", s);
    list<char> S(s, s+strlen(s));
    for(list<char>::iterator it=S.begin(), p; it!=S.end(); ++it) {
        if(it != S.begin()) {
            p = it; p--;
            if(*p == *it) {
                p = S.erase(p);
                it = S.erase(p);
                it--;
            }
        }
    }
    for(list<char>::iterator it=S.begin(), p; it!=S.end(); ++it) 
        printf("%c", *it);
    puts("");
    return 0;
}