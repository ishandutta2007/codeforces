#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

int s[100050];
pair<int, int> f[100050];
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for(int i=0; i<n; ++i) scanf("%d", &f[i].first), f[i].second=i;
    if(a == b) {
        for(int i=0; i<a; ++i) printf("1 ");
        for(int i=0; i<b; ++i) printf("2 ");
    } else if(a > b) {
        sort(f, f+n);
        for(int i=0; i<a; ++i) s[f[i].second] = 1;
        for(int i=0; i<n; ++i)
            printf("%d ", s[i]==1 ? 1 : 2);
    } else {
        for(int i=0; i<n; ++i) f[i].second *= -1;
        sort(f, f+n);
        for(int i=0; i<b; ++i) s[-f[i].second] = 2;
        for(int i=0; i<n; ++i)
            printf("%d ", s[i]==2 ? 2 : 1);
    }
    puts("");
    return 0;
}