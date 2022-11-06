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

struct dd
{int m[4];};

dd v[1005];

bool is_equal(dd a, dd  b)
{
    int i, j, f;
    for(i=0; i<4; i++)
    {
        rotate(a.m, (a.m)+1, (a.m)+4);
        f=0;
        for(j=0; j<4; j++)
            if (a.m[j]!=b.m[j])
                f=1;
        if (!f)
            return true;
    }
    return false;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, ans, f;
    string s1, s2, s3;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s1 >> s2 >> s3;
        v[i].m[0]=s1[0];
        v[i].m[1]=s1[1];
        v[i].m[2]=s2[1];
        v[i].m[3]=s2[0];
    }
    ans=1;
    for(i=1; i<n; i++)
    {
        f=1;
        for(j=0; j<i; j++)
            if (is_equal(v[i], v[j]))
                f=0;
        ans+=f;
    }
    cout << ans;
}