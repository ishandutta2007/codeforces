#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
int a[N];
pair<int, int> b[N];
int ap[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(a, a + n, greater<int>());
    sort(b, b + n);
    for(int i = 0; i < n; i++)
        ap[b[i].second] = a[i];
    for(int i = 0; i < n; i++)
        printf("%d ", ap[i]);
    puts("");
}