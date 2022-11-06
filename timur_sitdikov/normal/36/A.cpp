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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    int i, j, per, n, cnt=0, cur=1;
    string s;
    cin >> n >> s;
    for(i=0; i<(int)s.length(); i++)
        if (s[i]=='1')
            cnt++;
    for(i=0; i<(int)s.length(); i++)
        if (s[i]=='1')
            break;
    j=i;
    for(i++; i<(int)s.length(); i++)
        if (s[i]=='1')
            break;
    per=i-j;
    for(; i<(int)s.length(); i+=per)
        if (s[i]=='1')
            cur++;
        else break;
    if (cur==cnt)
        cout << "YES";
    else cout << "NO";
        


}