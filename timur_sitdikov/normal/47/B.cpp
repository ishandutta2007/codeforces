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

map<char, int> mp;
int m[3];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s1;
    int i;
    for(i=0; i<3; i++)
    {
        cin >> s1;
        if (s1[1]=='<')
            mp[s1[0]]++;
        else 
            mp[s1[2]]++;
    }
    for(i='A'; i<='C'; i++)
        m[mp[i]]=i;
    if (m[0] && m[1] && m[2])
        i=i;
    else 
    {
        printf("Impossible");
        return 0;
    }
    for(i=2; i>=0; i--)
        putchar(m[i]);
}