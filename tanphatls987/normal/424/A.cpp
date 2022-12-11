#include "iostream"
#include <fstream>
#include "cstdio"
#include "string"
using namespace std;

int main()
{
    int n, si = 0, st = 0, dem =0;
    string s;
cin>>n>>s;
    int l = s.length();
    for (int i=0;i<l;i++)
        if ((int)s[i]==120)
            si++;
        else
            st++;
    if (si<st)
    {
        int i=0;
        while (si<st)
        {
            if ((int)s[i]!=120)
            {
                s[i] += 32;
                si++;
                st--;
                dem++;
            }
            i++;
        }
    }
    else
    {
        int i=0;
        while (si>st)
        {
            if ((int)s[i]==120)
            {
                s[i] -= 32;
                st++;
                si--;
                dem++;
            }
            i++;
        }
    }
    cout << dem << endl << s;
    return 0;
}