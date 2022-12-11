#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 400001;
const int LOG = 19;
int jump[N][LOG];
ll jw[N][LOG];
ll w[N];

int main()
{
    w[0] = 1e17;
    for(int i = 0; i < LOG; i++)
        jw[1][i] = w[0];
    int q, cnt = 1, last = 0;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        ll a, b;
        scanf("%d %lld %lld", &type, &a, &b);
        a ^= last; b ^= last;
        if(type == 1)
        {
            cnt++;
            w[cnt] = b;
            for(int i = LOG - 1; i >= 0; i--)
                if(w[jump[a][i]] < b)
                    a = jump[a][i];
            if(w[a] < b) a = jump[a][0];
            jump[cnt][0] = a;
            jw[cnt][0] = w[a];
            for(int i = 1; i < LOG; i++)
            {
                jump[cnt][i] = jump[jump[cnt][i-1]][i-1];
                jw[cnt][i] = jw[cnt][i-1] + jw[jump[cnt][i-1]][i-1];
            }
        }
        else
        {
            last = 0;
            if(w[a] <= b)
            {
                last++;
                b -= w[a];
                for(int i = LOG - 1; i >= 0; i--)
                    if(jw[a][i] <= b)
                    {
                        last += (1 << i);
                        b -= jw[a][i];
                        a = jump[a][i];
                    }
            }
            printf("%d\n", last);
        }
    }
}