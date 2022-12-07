#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#define maxn 4005
using namespace std;

bool judge(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

set<char> save;
char s[maxn];
int main(){
    bool f = 1;
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    int siz = 0;
    int l = 0;
    for (int i = 0; i < n; i++){
        if (judge(s[i])){
            save.clear();
            siz = 0;
        }
        else{
            save.insert(s[i]);
            siz++;
            if (siz >= 3 && save.size() >= 2){
                ans++;
                siz = 0;
                save.clear();
                if (f) f = 0;
                else printf(" ");
                for (int j = l; j < i; j++) printf("%c", s[j]);
                l = i;
                i--;
            }
        }
    }
    if (f) f = 0;
    else printf(" ");
    for (int j = l; j < n; j++) printf("%c", s[j]);
    return 0;
}