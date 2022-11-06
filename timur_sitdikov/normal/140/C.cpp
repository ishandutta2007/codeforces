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

map <int, int> mp;
set < pair <int, int> > st;
vector <int> ans[3];

int main()
{   
    int n, i, sz, a, b, c;
    map <int, int>::iterator it;
    set < pair < int, int > >::iterator it1, it2, it3;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        mp[a]++;
    }
    for(it=mp.begin(); it!=mp.end(); it++)
        st.insert(make_pair(it->second, it->first));
    while(st.size()>2)
    {
        it1=st.end();
        it1--;
        it2=it1;
        ans[0].push_back(it2->second);
        it1--;
        it3=it1;
        ans[1].push_back(it3->second);
        it1--;
        ans[2].push_back(it1->second);
        if (it1->first>1)
            st.insert(make_pair(it1->first-1, it1->second));
        if (it2->first>1)
            st.insert(make_pair(it2->first-1, it2->second));
        if (it3->first>1)
            st.insert(make_pair(it3->first-1, it3->second));
        st.erase(it1);
        st.erase(it2);
        st.erase(it3);
    }
    printf("%d\n", ans[0].size());
    sz=ans[0].size();
    for(i=0; i<sz; i++)
    {
        a=max(ans[0][i], max(ans[1][i], ans[2][i]));
        c=min(ans[0][i], min(ans[1][i], ans[2][i]));
        if (a!=ans[0][i] && c!=ans[0][i]) b=ans[0][i];
        if (a!=ans[1][i] && c!=ans[1][i]) b=ans[1][i];
        if (a!=ans[2][i] && c!=ans[2][i]) b=ans[2][i];
        printf("%d %d %d\n", a, b, c);
    }
}