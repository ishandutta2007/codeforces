#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>

string s;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, n, a=0, b=0;
    cin >> s;
    n=s.length();
    for(i=0; i<n; i++)
        if (s[i]<'a')
            a++;
        else b++;
    if (a>b)
    {
        for(i=0; i<n; i++)
            if (s[i]>='a')
                s[i]=s[i]-'a'+'A';
    }
    else
    {
        for(i=0; i<n; i++)
            if (s[i]<'a')
                s[i]=s[i]-'A'+'a';
    }
    cout << s;
}