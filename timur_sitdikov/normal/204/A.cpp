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

long long st10(long long st)
{
    long long ans=1;
    for(int i=0; i<st; i++)
        ans*=10;
    return ans;
}

long long get_num(long long v)
{
    long long ans=0, fd, nd, i;
    if (!v) return 0;
    if (v<10) return v;
    for(nd=1, fd=v; fd>=10; fd/=10, nd++);
    for(i=2; i<nd; i++)
        ans+=9*st10(i-2);
    ans+=9;
    for(i=1; i<fd; i++)
        ans+=st10(nd-2);
    ans+=(v%st10(nd-1))/10+1;
    if (v%10<fd) ans--;
    return ans;
}

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long l, r, ans;
    cin >> l >> r;
    cout << get_num(r) - get_num(l-1);
}