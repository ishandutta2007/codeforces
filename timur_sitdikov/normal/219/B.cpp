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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long ans, v, p, cur, i, j, len;
    string num;
    cin >> num >> p;
    len=num.length();
    ans=0;
    for(i=0; i<len; i++)
        num[i]-='0';
    for(i=0; i<len; i++)
        ans=ans*10+num[i];
    v=ans;
    for(i=0; i<len; i++)
    {
        cur=0;
        for(j=0; j<i; j++)
            cur=cur*10+num[j];
        for(; j<len; j++)
            cur=cur*10+9;
        if (cur<=v && v-p<=cur)
        {
            cout << cur;
            return 0;
        }
        cur=0;
        for(j=0; j<i; j++)
            cur=cur*10+num[j];
        cur--;
        if (cur<0)
            continue;
        for(; j<len; j++)
            cur=cur*10+9;
        if (cur<=v && v-p<=cur)
        {
            cout << cur;
            return 0;
        }
    }
    cout << ans;
}