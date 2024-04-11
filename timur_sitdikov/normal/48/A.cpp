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

int cmp(string s1, string s2)
{
    if (s1=="rock" && s2=="scissors")
        return 1;
    if (s1=="scissors" && s2=="paper")
        return 1;
    if (s1=="paper" && s2=="rock")
        return 1;
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (cmp(s1, s2) && cmp(s1, s3))
    {
        putchar('F');
        return 0;
    }
    if (cmp(s2, s1) && cmp(s2, s3))
    {
        putchar('M');
        return 0;
    }
    if (cmp(s3, s1) && cmp(s3, s2))
    {
        putchar('S');
        return 0;
    }
    putchar('?');
}