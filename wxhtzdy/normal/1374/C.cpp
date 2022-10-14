#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        string x;
        cin >> x;
        int k = 0;
        int brojac = 0;
        for(int i = 0; i < x.length(); i++)
        {
            if(x[i] == '(') k++;
            else k--;
            if(k < 0)
            {
                brojac++;
                k++;
            }
        }
        cout << brojac << endl;
    }
}