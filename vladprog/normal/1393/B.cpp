#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int cnt1[N];
int cnt2[N];

int f(int x)
{
    if(x>=8)
        return 8;
    if(x>=6)
        return 6;
    if(x>=4)
        return 4;
    if(x>=2)
        return 2;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        cnt2[f(cnt1[x])]--;
        cnt1[x]++;
        cnt2[f(cnt1[x])]++;
    }
    int q;
    cin>>q;
    while(q--)
    {
        char c;
        int x;
        cin>>c>>x;
        cnt2[f(cnt1[x])]--;
        if(c=='+')
            cnt1[x]++;
        else
            cnt1[x]--;
        cnt2[f(cnt1[x])]++;
        bool ok=false;
        for(int a=4;a<=8;a+=2)
            if(cnt2[a]>=1)
            {
                cnt2[a]--;
                cnt2[a-4]++;
                for(int b=2;b<=8;b+=2)
                    if(cnt2[b]>=1)
                    {
                        cnt2[b]--;
                        cnt2[b-2]++;
                        for(int c=2;c<=8;c+=2)
                            if(cnt2[c]>=1)
                                ok=true;
                        cnt2[b]++;
                        cnt2[b-2]--;
                    }
                cnt2[a]++;
                cnt2[a-4]--;
            }
        cout<<(ok?"YES\n":"NO\n");
    }
}