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

set<string> st;

int main()
{   
    int i, l, f=0, ans=0;
    string tmp;
    char c;
    while((c=getchar())!=EOF)
    {
        if (c=='+')
        {
            f=0;
            tmp.clear();
            continue;
        }
        if (c=='-')
        {
            f=1;
            tmp.clear();
            continue;
        }
        if (c==':')
        {
            f=2;
            tmp.clear();
            continue;
        }
        if (c=='\n')
        {
            if (f==0) st.insert(tmp);
            if (f==1) st.erase(tmp);
            if (f==2) ans+=tmp.length()*st.size();
            tmp.clear();
            continue;
        }
        tmp.push_back(c);
    }
    if (!tmp.empty())
    {
        if (f==0) st.insert(tmp);
        if (f==1) st.erase(tmp);
        if (f==2) ans+=tmp.length()*st.size();
    }
    printf("%d", ans);
}