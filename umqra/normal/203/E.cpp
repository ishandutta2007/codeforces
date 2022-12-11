#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
const int INF = 1e9;
struct robot
{
    long long c, f;
} mas[N];
bool cmp1 ( robot a, robot b )
{
    if ( a.c == b.c )
        return a.f > b.f;
    return a.c > b.c;
}
bool cmp2 ( robot a, robot b )
{
    return a.f < b.f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, d, s;
    cin >> n >> d >> s;
    for ( int i = 0; i < n; i++ )
    {
        cin >> mas[i].c >> mas[i].f;
        int l;
        cin >> l;
        if ( l < d )
            mas[i].f = INF;
    }
    sort(mas, mas + n, cmp1);
    for ( int i = 0; i <= n; i++ )
    {
        if ( i == n || !mas[i].c )
        {
            sort(mas, mas + i, cmp2);
            break;
        }
    }
    long long c = mas[0].c;
    int ans1 = 1;
    int last = 1;
    int s1 = s - mas[0].f;
    if ( s1 < 0 )
    {
        s1 = 0;
        ans1 = 0;
        c = 0;
    }
    while ( c && last < n )
    {
        c += mas[last].c;
        c--;
        last++;
        ans1++;
    }



    int i = 1, j = last, k = n - 1;
    while ( j <= k )
    {
        int t1 = INF, t2 = mas[k].f;
        if ( mas[i].f < mas[j].f )
            t1 = mas[i].f;  
        if ( t1 <= t2 && t1 <= s1  )
        {
            j++;
            ans1++;
            i++;
            s1 -= t1;
        }
        else if ( t2 < t1 && t2 <= s1 )
        {
            k--;
            ans1++;
            s1 -= t2;
        }
        else
            break;
    }

    int ans2 = 0, s2 = s;
    sort(mas, mas + n, cmp2);
    for ( int i = 0; i < n; i++ )
    {
        if ( mas[i].f > s2 )
            break;  
        s2 -= mas[i].f;
        ans2++;
    }

    if ( ans2 > ans1 )
        cout << ans2 << ' ' << s - s2;
    else if ( ans2 == ans1 )
    {
        if ( s2 > s1 )
            cout << ans2 << ' ' << s - s2;
        else
            cout << ans1 << ' ' << s - s1;
    }
    else
        cout << ans1 << ' ' << s - s1;
    return 0;
}



/*
int k = n - 1, j = last;
    for ( int i = 1; i < last; i++ )
    {
        if ( mas[i].c == 0 )
            break;
        if ( k < last || j > n - 1 )
            break;
        if ( s1 < mas[i].f )
            break;
        if ( mas[i].f < mas[j].f )
        {
            ans1++;
            s1 -= mas[i].f;
            j++;
        }
    }
    for ( int i = k; i >= j; i-- )
    {
        if ( mas[i].f > s1 )
            break;
        ans1++;
        s1 -= mas[i].f;
    }
*/