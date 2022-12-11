#include <iostream>
using namespace std;
typedef long long ll;
ll mas[1000000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    ll min_t = (int)1e11;
    int ans, cnt = 0;
    for ( int i = 0; i < n; i++ )
    {
        cin >> mas[i];
        if ( mas[i] < min_t )
        {
            min_t = mas[i];
            ans = i + 1;
        }
    }
    for ( int i = 0; i < n; i++ )
        if ( mas[i] == min_t )
            cnt++;
    if ( cnt > 1 )
        cout << "Still Rozdil";
    else
        cout << ans;
    return 0;
}