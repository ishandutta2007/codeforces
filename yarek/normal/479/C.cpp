#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> p[5000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p + n);
    int d = 0;
    for(int i = 0; i < n; i++)
        if(d <= p[i].second) d = p[i].second;
        else d = p[i].first;
    printf("%d\n", d);
}