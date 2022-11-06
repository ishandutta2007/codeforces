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
vector<string> ans;

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, f=0, f1=0;
    string tmp;
    cin >> s;
    for(i=0; i<(int)s.length(); i++)
    {
        if (s[i]=='@')
        {
            f1=1;
            if (tmp.empty() || f)
            {
                printf("No solution");
                return 0;
            }
            tmp.push_back(s[i]);
            f=1;
        }
        else
        {
            tmp.push_back(s[i]);
            if (f)
            {
                ans.push_back(tmp);
                tmp.clear();
                f=0;
            }
        }
    }
    if (!f1 || s[i-1]=='@')
    {
        printf("No solution");
        return 0;
    }

    ans[ans.size()-1]+=tmp;
    for(i=0; i<(int)ans.size(); i++)
    {
        if (i) cout << ",";
        cout << ans[i];
        
    }

}