#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<class T> inline bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

#define ALL(x) x.begin(), x.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REPD(i, n) for(int i = n - 1; i >= 0; i--)
#define FORD(i, a, b) for(int i = b; i >= a; i--)

const int N = 300001;
queue<int> unread[N];
vector<int> ev;

int main()
{
    int n, q, ans = 0, mt = 0;
    scanf("%d %d", &n, &q);
    while(q--)
    {
        int type, x;
        scanf("%d %d", &type, &x);
        if(type == 1)
        {
            unread[x].push(ev.size());
            ev.push_back(x);
            ans++;
        }
        if(type == 2)
        {
            while(!unread[x].empty())
            {
                unread[x].pop();
                ans--;
            }
        }
        if(type == 3)
        {
            while(mt < x)
            {
                int a = ev[mt];
                if(!unread[a].empty() && unread[a].front() == mt)
                {
                    unread[a].pop();
                    ans--;
                }
                mt++;
            }
        }
        printf("%d\n", ans);
    }
}