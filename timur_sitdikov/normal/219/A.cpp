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

int m[1000];

int gcd(int a, int b)
{return b? gcd(b, a%b): a;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, l, g;
    string s;
    cin >> k >> s;
    for(i=0; i<(int)s.length(); i++)
        m[s[i]]++;
    for(i='a'; i<='z'; i++)
        if (m[i] && m[i]%k)
        {
            printf("-1");
            return 0;
        }
    
    for(i=0; i<k; i++)
        for(j='a'; j<='z'; j++)
            for(l=0; l<m[j]/k; l++)
                putchar(j);
}