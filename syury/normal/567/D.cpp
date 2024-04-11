#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int n, k, a, m;
set<int> t;
int ans = 0;

int main(){
    scanf("%d%d%d%d", &n, &a, &k, &m);
    t.insert(0); t.insert(n + 1);
    ans = (n + 1)/(k + 1);
    for(int i = 0; i < m; i++){
        int pos;
        scanf("%d", &pos);
        set<int>::iterator next = t.upper_bound(pos);
        set<int>::iterator prev = next--;
        int inext = *next, iprev = *prev;
        ans -= (iprev - inext)/(k + 1);
        ans += (pos - inext)/(k + 1) + (iprev - pos)/(k + 1);
        t.insert(pos);
        if(ans < a){printf("%d", i + 1); return 0;}
    }
    printf("-1");
    return 0;
}