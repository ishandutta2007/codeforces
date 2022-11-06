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

set<pair<int, int> > st;
set<pair<int, int> >::iterator it, it1;
vector<int> ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, r, l, tmp;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> l >> r;
        if (l>r)
            swap(l, r);
        st.insert(make_pair(r, l));
    }
    while(!st.empty())
    {
        tmp=st.begin()->first;
        ans.push_back(tmp);
        st.erase(st.begin());
        for(it=st.begin(); it!=st.end(); it=it1)
        {
            it1=it;
            it1++;
            if (it->second<=tmp)
                st.erase(it);
        }
    }
    printf("%d\n", (int)ans.size());
    for(i=0; i<(int)ans.size(); i++)
        printf("%d ", ans[i]);
}