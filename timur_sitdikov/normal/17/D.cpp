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
using namespace std;

string b, n;

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long c, p, q, r, st10, tmp, p2, p4, p8, ans;
    int i, j;
    cin >> b >> n >> c;
    reverse(b.begin(), b.end());
    reverse(n.begin(), n.end());
    r=0; 
    st10=1;
    for(i=0; i<b.length(); i++)
    {
        r=(r+st10*(b[i]-'0'))%c;
        st10=(st10*10)%c;
    }
    for(i=0; i<n.length() && n[i]=='0'; i++)
        n[i]='9';
    n[i]--;
    tmp=r;
    p=1;
    for(i=0; i<n.length(); i++)
    {
        for(j=0; j<(n[i]-'0'); j++)
            p=(p*tmp)%c;
        p2=(tmp*tmp)%c;
        p4=(p2*p2)%c;
        p8=(p4*p4)%c;
        tmp=(p2*p8)%c;
    }
    q=(p*r)%c;
    ans=(q+c-p)%c;
    if (!ans)
        ans=c;
    cout << ans;
}