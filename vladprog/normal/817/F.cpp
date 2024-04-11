#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100;

bitset<2*N> cur,one;

int t[N],l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,int> comp,rev;
    comp[1];
    for(int i=1;i<=n;i++)
        cin>>t[i]>>l[i]>>r[i],
        r[i]++,
        comp[l[i]],
        comp[r[i]];
    int nxt=0;
    for(auto&p:comp)
        p.second=nxt++,
        rev[p.second]=p.first;
    one=~one;
    cur=one;
    for(int i=1;i<=n;i++)
    {
        int T=t[i],
            L=comp[l[i]],
            R=comp[r[i]];
        if(T==1)
            cur&=~(one>>(2*N-(R-L))<<L);
        else if(T==2)
            cur|=(one>>(2*N-(R-L))<<L);
        else
            cur^=(one>>(2*N-(R-L))<<L);
//        cout<<T<<" "<<L<<" "<<R<<" -> ";
//        for(int i=0;i<10;i++)
//            cout<<cur[i];
//        cout<<" -> ";
        cout<<rev[cur._Find_first()]<<"\n";
    }
}