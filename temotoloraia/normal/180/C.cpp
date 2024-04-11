#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;

int main()
{
    cin >> s;
    int n = s.length(); int ct = 0;
    
    for(int i = 0; i < n; i++)
        if(s[i] >= 'a' && s[i] <= 'z') ct++;
        
    int ret = min(ct, n - ct); int x = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
                 x++; ct--;
        }
        ret = min(ret, x + (n - i - 1 - ct));
    }
    cout << ret<<endl;
}