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

int v[2][200];


int is_good(char c)
{
    return !(c==EOF || c==10 || c==13);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    char c;
    for(i=0; i<2; )
    {
        c=getchar();
        if (!is_good(c))
            i++;
        if (i<2)
            v[i][c]++;
    }
    for(i='A'; i<='Z'; i++)
        if (v[0][i]<v[1][i])
        {
            cout << "NO";
            return 0;
        }
    for(i='a'; i<='z'; i++)
        if (v[0][i]<v[1][i])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
}