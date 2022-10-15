#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <bitset>
#include <sstream>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define X first
#define Y second
const int INF = 1e9;

LL a1, b1, a2, b2;

map<LL, int > mp, mp2;
map<LL, pair<LL, LL> > c2, c22;

queue<LL> que;

int main()
{
    cin >> a1 >> b1 >> a2 >> b2;
    
    LL A = a1 * b1, B = a2 * b2;
    
    mp[B] = 0; c2[B] = make_pair(a2, b2);
    que.push(B);
    while(!que.empty())
    {
        LL now = que.front(); que.pop();
        if(now % 3 == 0)
        {
            LL cur = now / 3ll * 2ll;
            if(!mp.count(cur))
            {
                mp[cur] = mp[now] + 1;
                
                c2[cur] = c2[now];
                if(c2[cur].X % 3 == 0) c2[cur].X /= 3, c2[cur].X *= 2;
                else c2[cur].Y /= 3, c2[cur].Y *= 2;
                
                que.push(cur);
            }
        }
        if(now % 2 == 0)
        {
            LL cur = now / 2ll;
            if(!mp.count(cur))
            {
                mp[cur] = mp[now] + 1;
                
                c2[cur] = c2[now];
                if(c2[cur].X % 2 == 0) c2[cur].X /= 2;
                else c2[cur].Y /= 2;
                
                que.push(cur);
            }
        }
    }
    
    LL ans = (1 << 30), Ans = B;
    mp2[A] = 0; c22[A] = make_pair(a1, b1);
    que.push(A);

    while(!que.empty())
    {
        LL now = que.front(); que.pop();
        if(mp.count(now))
        {
            if(mp[now] + mp2[now] < ans)
            {
                ans = mp[now] + mp2[now], Ans = now;
            }
        }
        if(now % 3 == 0)
        {
            LL cur = now / 3ll * 2ll;
            if(!mp2.count(cur))
            {
                mp2[cur] = mp2[now] + 1;
                
                c22[cur] = c22[now];
                if(c22[cur].X % 3 == 0) c22[cur].X /= 3, c22[cur].X *= 2;
                else c22[cur].Y /= 3, c22[cur].Y *= 2;
                
                que.push(cur);
            }
        }
        if(now % 2 == 0)
        {
            LL cur = now / 2ll;
            if(!mp2.count(cur))
            {
                mp2[cur] = mp2[now] + 1;
                
                c22[cur] = c22[now];
                if(c22[cur].X % 2 == 0) c22[cur].X /= 2;
                else c22[cur].Y /= 2;
                
                que.push(cur);
            }
        }
    }
    
    if(ans == (1 << 30))
    {
        printf("-1\n");
        return 0;
    }
    
    cout << ans << endl;
    cout << c22[Ans].X << " " << c22[Ans].Y << endl;
    cout << c2[Ans].X << " " << c2[Ans].Y << endl;
    
    
    
    return 0;
}