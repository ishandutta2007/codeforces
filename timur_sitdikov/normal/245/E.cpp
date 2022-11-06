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
#define xx first
#define yy second

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int cur, ans, i, s1, s2;
    string s;
    cin >> s;
    ans=cur=s1=s2=0;
    for(i=0; i<(int)s.length(); i++)
    {
        if (s[i]=='-')
            cur--;
        else cur++;
        /*if (abs(cur)>ans)
            ans=abs(cur);*/
        if (cur>0 && s1<cur)
            s1=cur;
        if (cur<0 && s2<abs(cur))
            s2=abs(cur);
    }
    ans=s1+s2;
    cout << ans;
}