#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int Q, n, a[100001], m;
vector<int> vec[100001];
long long ans1, ans2, ans, ansmax, sumle, sumri;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
        if(i > 1 and a[i - 1] != a[i])
        {
            vec[a[i - 1]].push_back(a[i]);
            vec[a[i]].push_back(a[i - 1]);
        }
    }
    ans = 0;
    ansmax = -9000000000000000000ll;
    for(int i = 1; i <= n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
        sumri = 0;
        for(vector<int>::iterator itr = vec[i].begin(); itr != vec[i].end(); itr++)
        {sumri += *itr;}
        sumle = 0;
        //printf("%d %I64d %I64d\n", i, sumri, sumle);
        ans1 = 0x7fffffffffffffffll;
        ans2 = sumri - (long long)i * vec[i].size();
        for(vector<int>::iterator itr = vec[i].begin(); itr != vec[i].end(); itr++)
        {
            ans1 = min(ans1, (long long)(itr - vec[i].begin()) * (*itr) - sumle + sumri - (long long)(vec[i].end() - itr) * (*itr));
            sumri -= *itr;
            sumle += *itr;
            if(*itr <= i) ans2 = (long long)(itr - vec[i].begin() + 1) * i - sumle + sumri - (long long)(vec[i].end() - itr - 1) * i;
            
        }
        //printf("%I64d %I64d\n", ans1, ans2);
        ansmax = max(ansmax, ans2 - ans1);
    }
    for(int i = 1; i < m; i++) ans = ans + abs(a[i + 1] - a[i]);
    if(ansmax == -9000000000000000000ll) printf("0\n"); else printf("%I64d\n", ans - ansmax);
    fclose(stdin);
    return 0;
}