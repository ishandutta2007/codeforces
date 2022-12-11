#include <iostream>
#include <algorithm>
using namespace std;
struct people
{
    long long t, ind;
} mas[1000000];
int ans[1000000];
int index, index_ans;
bool cmp ( people a, people b )
{
    if ( a.t < b.t )
        return true;
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    long long n, mem, a, b;
    cin >> n >> mem >> a >> b;
    for ( int i = 0; i < n; i++ )
    {
        long long f, s;
        cin >> f >> s;
        long long t = f * a + s * b;
        mas[index].t = t;
        mas[index++].ind = i;
    }
    sort(mas, mas + index, cmp);
    for ( int i = 0; i < index; i++ )
    {
        if ( mem < mas[i].t )
            break;
        mem -= mas[i].t;
        ans[index_ans++] = mas[i].ind;
    }
    cout << index_ans << endl;
    for ( int i = 0; i < index_ans; i++ )
        cout << ans[i] + 1 << ' ';
    return 0;
}