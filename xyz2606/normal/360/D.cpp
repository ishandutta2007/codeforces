#include<cstring>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
vector<int> ord, dvi;
int rt, ans, n, m, p, d, a[11111], x, cnt[11111];
int gcd(int a, int b) {return b?gcd(b, a % b):a;}
bool flag;
int pom(long long x, int n)
{
    long long rtn = 1;
    while(n)
    {
        if(n & 1) rtn = (rtn * x) % p;
        n /= 2;
        x = (x * x) % p;
    }
//rintf("%lld\n", rtn);
    return (int) rtn;
}
int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i * i < p; i++) if((p - 1) % i == 0)
    {
        dvi.push_back(i);
        if(i * i != (p - 1)) dvi.push_back((p - 1) / i);
    }
    sort(dvi.begin(), dvi.end());
    //printf("%d\n", rt);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        for(int j = 0; j <dvi.size(); j++) if(pom(x, dvi[j]) == 1)
        {
            a[i] = (p - 1) / dvi[j];
            break;
        }
    }
    d = p - 1;
    for(int j = 1; j <= m; j++)
    {
        scanf("%d", &x);
        d = gcd(d, x);
    }
    p = (p - 1) / d;
    ans = 0;
    for(int i = 1; i <= n; i++) a[i] = gcd(a[i], p), ord.push_back(a[i] == 0?p:a[i]);
    //printf("%d %d\n", ord[0], ord[1]);
    dvi.clear();
    for(int i = 1; i * i <= p; i++) if(p % i == 0)
        
    {
        dvi.push_back(i);
        if(i * i != p) dvi.push_back(p / i);
    }
    ans = 0;
    sort(dvi.begin(), dvi.end());
    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());
    for(int i = dvi.size() - 1; i >= 0; i--)
    {
        cnt[i] = p / dvi[i];
        for(int j = i + 1; j < dvi.size(); j++) if(dvi[j] % dvi[i] == 0)
            cnt[i] -= cnt[j];
        for(int j = 0; j < ord.size(); j++) if(dvi[i] % ord[j] == 0)
        {
            ans += cnt[i];
            break;
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}