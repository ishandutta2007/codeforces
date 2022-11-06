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

map<string, int> files;
map<string, int>::iterator iti;
map<string, set<string>> dirs;
map<string, set<string>>::iterator its;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, mx1, mx2;
    char c[105];
    string s, s1, s2;
    while(scanf("%s", &c) == 1){
        s = c;
        for(j = 3; s[j] != '\\'; j++);
        s1 = s.substr(0, j);
        files[s1]++;
        s2 = "";
        for(j++; j < (int)s.length(); j++){
            s2.pb(s[j]);
            if (s[j] == '\\')
                dirs[s1].insert(s2);
        }
    }
    mx2 = 0;
    for(its = dirs.begin(); its != dirs.end(); its++)
        mx2 = max(mx2, (int)its->second.size());
    mx1 = 0;
    for(iti = files.begin(); iti != files.end(); iti++)
        mx1 = max(mx1, iti->second);
    cout << mx2 << " " << mx1;
}