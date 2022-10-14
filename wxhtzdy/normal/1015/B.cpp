#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string x, t;
    cin >> x >> t;
    string str1 = x, str2 = t;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    int brojac = 0;
    for(int i = 0; i < n; i++)
    {
        if(str1[i] != str2[i])
        {
            cout << -1;
            return 0;
        }
    }
    str1 = x;
    str2 = t;
    for(int i = 0; i < n; i++)
    {
        if(x[i] != t[i])
        {
            int index;
            for(int j = i+1; j < n; j++)
            {
                if(t[i] == x[j])
                {
                    index = j;
                    break;
                }
            }
            for(int j = index; j > i; j--)
            {
                brojac++;
                swap(x[j-1], x[j]);
            }
        }
    }
    cout << brojac << "\n";
    x = str1;
    t = str2;
    for(int i = 0; i < n; i++) //abcdef
    {                          //abdfec
        if(x[i] != t[i])
        {
            int index;
            for(int j = i+1; j < n; j++)
            {
                if(t[i] == x[j])
                {
                    index = j;
                    break;
                }
            }
            for(int j = index; j > i; j--)
            {
                swap(x[j-1], x[j]);
                cout << j << " ";
            }
        }
    }
    return 0;
}