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

string s, ans;
int v[200], pos[200], num[200];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j=0, last=0;
    cin >> s;
    for(i=0; i<(int)s.length(); i++) v[s[i]]=1;
    for(i='z'; i>='a'; i--)
        if (v[i])
        {
            for(j=last; j<(int)s.length(); j++)
                if (s[j]==i) {pos[i]=j; last=j; num[i]++;}
            for(j=0; j<num[i]; j++) ans.push_back(i);
        }
    cout << ans;
}