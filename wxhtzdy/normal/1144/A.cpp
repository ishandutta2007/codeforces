#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        bool b = true;
        string x;
        cin >> x;
        sort(x.begin(), x.end());
        for(int i = 1; i < x.length(); i++)
        {
            if(x[i] != x[i-1]+1) b = false;
        }
        if(b) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}