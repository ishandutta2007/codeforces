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

string s;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, ans=0, b=0;
    cin >> s;
    for(i=0; i<(int)s.length(); i++)
        if (s[i]=='(') {b++; ans++;}
        else
        {
            b--; 
            if (b<0) b=0;
            else ans++;
        }
    ans-=b;
    printf("%d", ans);
}