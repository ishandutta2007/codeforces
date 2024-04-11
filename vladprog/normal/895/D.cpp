#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e6+100,MOD=1e9+7;

int f[N],rf[N];

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

void m(int&x,int y)
{
    x=x*y%MOD;
}

void p(int&x,int y)
{
    x=(x+y)%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a,b;
    cin>>a>>b;
    int n=a.size();
    f[0]=1;
    for(int i=1;i<=N-1;i++)
        f[i]=f[i-1]*i%MOD;
    rf[N-1]=ppow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        rf[i]=rf[i+1]*(i+1)%MOD;
    int k=n;
    int cnt[26]={};
    for(char c:a)
        cnt[c-'a']++;
    int cur=f[n];
    for(int i=0;i<26;i++)
        cur=cur*rf[cnt[i]]%MOD;
    int ans=(MOD-cur)%MOD;
//    cout<<"-"<<cur<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;'a'+j<b[i];j++)
            if(cnt[j])
            {
                m(cur,rf[k]);
                m(cur,f[cnt[j]]);
                cnt[j]--;
                k--;
                m(cur,f[k]);
                m(cur,rf[cnt[j]]);
                p(ans,cur);
//                cout<<"+"<<cur<<"\n";
                m(cur,rf[k]);
                m(cur,f[cnt[j]]);
                cnt[j]++;
                k++;
                m(cur,f[k]);
                m(cur,rf[cnt[j]]);
            }
        int j=b[i]-'a';
        if(!cnt[j])
            break;
        m(cur,rf[k]);
        m(cur,f[cnt[j]]);
        cnt[j]--;
        k--;
        m(cur,f[k]);
        m(cur,rf[cnt[j]]);
    }

    k=n;
    for(int i=0;i<26;i++) cnt[i]=0;
    for(char c:a)
        cnt[c-'a']++;
    cur=f[n];
    for(int i=0;i<26;i++)
        cur=cur*rf[cnt[i]]%MOD;
    for(int i=0;i<n;i++)
    {
        for(int j=25;'a'+j>a[i];j--)
            if(cnt[j])
            {
                m(cur,rf[k]);
                m(cur,f[cnt[j]]);
                cnt[j]--;
                k--;
                m(cur,f[k]);
                m(cur,rf[cnt[j]]);
                p(ans,cur);
//                cout<<"+"<<cur<<"\n";
                m(cur,rf[k]);
                m(cur,f[cnt[j]]);
                cnt[j]++;
                k++;
                m(cur,f[k]);
                m(cur,rf[cnt[j]]);
            }
        int j=a[i]-'a';
        if(!cnt[j])
            break;
        m(cur,rf[k]);
        m(cur,f[cnt[j]]);
        cnt[j]--;
        k--;
        m(cur,f[k]);
        m(cur,rf[cnt[j]]);
    }
    cout<<ans;
}