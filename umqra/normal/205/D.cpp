#include <iostream>
#include <algorithm>
using namespace std;
int cards[1000000][2];
int mas[1000000];
int check ( int c, int n )
{
    int t = 0, cnt = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( cards[i][0] == c )
            t++;
    }                             
    for ( int i = 0; i < n; i++ )
    {
        if ( t >= (n + 1) / 2 )
            break;
        if ( cards[i][0] != c && cards[i][1] == c )
        {
            t++;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, res = -1;
    cin >> n;
    int index = 0;
    for ( int i = 0; i < n; i++ )
    {
        cin >> cards[i][0] >> cards[i][1];
        mas[index++] = cards[i][0];
        if ( cards[i][0] != cards[i][1] )
            mas[index++] = cards[i][1];
    }
    sort(mas, mas + index);
    int cnt = 1;
    for ( int i = 1; i < index; i++ )
    {
        if ( mas[i] == mas[i - 1] )
            cnt++;
        else
        {
            if ( cnt >= (n + 1) / 2 )
            {   
                 int ans = check(mas[i - 1], n);
                 if ( ans < res || res == -1 )
                    res = ans;
            }
            cnt = 1;
        }   
    }
    if ( cnt >= (n + 1) / 2 )
    {
        int ans = check(mas[index - 1], n);
        if ( ans < res || res == -1 )
            res = ans;
    }
    cout << res;
    return 0;
}