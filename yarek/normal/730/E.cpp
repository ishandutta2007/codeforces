#include <bits/stdc++.h>
using namespace std;

const int N = 101;
pair<int, int> a[N];
pair<int, int> b[N];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = n * (n - 1) / 2;
    for(int i = 0; i < n; i++)
    {
        int A, D;
        scanf("%d %d", &A, &D);
        a[i] = make_pair(A, -i);
        b[i] = make_pair(A + D, -i);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i] < a[j] && a[j] < b[i] && b[i] < b[j])
                ans++;
            else if(a[i] > a[j] && a[j] > b[i] && b[i] > b[j])
                ans++;
            else if(max(a[i], b[i]) < min(a[j], b[j])) ans--;
    printf("%d\n", ans);
}