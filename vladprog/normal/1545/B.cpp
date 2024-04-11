#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,MOD=998244353;

int fact[N],ifact[N];

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%MOD;
    ifact[N-1]=ppow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        ifact[i]=ifact[i+1]*(i+1)%MOD;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int oneone=0,zero=0;
        bool one=false;
        for(char c:s)
            if(c=='0')
                zero++,
                one=false;
            else if(one)
                oneone++,
                one=false;
            else
                one=true;
        cout<<fact[oneone+zero]*ifact[oneone]%MOD*ifact[zero]%MOD<<"\n";
    }
}