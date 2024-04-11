#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string x, t;
    cin >> x >> t;
    reverse(x.begin(), x.end());
    reverse(t.begin(), t.end());
    int index = 0;
    for(int i = 0; i < min(x.length(), t.length()); i++)
    {
        if(x[i] == t[i]) index++;
        else break;
    }
    cout << x.length()+t.length()-2*index;
    return 0;
}