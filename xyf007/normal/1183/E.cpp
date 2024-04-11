#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
using namespace std;
int n, k, sum;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> s;
    queue<string> q;
    set<string> st;
    q.push(s);
    st.insert(s);
    while (!q.empty() && (int)st.size() < k)
    {
        string u = q.front();
        q.pop();
        for (int i = 0; i < (int)u.size(); i++)
        {
            string temp = u;
            temp.erase(i, 1);
            if (!st.count(temp) && (int)st.size() < k)
            {
                st.insert(temp);
                q.push(temp);
                sum += n - temp.size();
            }
        }
    }
    if ((int)st.size() < k)
    {
        printf("-1");
    }
    else
    {
        printf("%d", sum);
    }
    return 0;
}