#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int mod=555;
const int maxn=4e6+5;
int inv2=(p+1)/2;
int po[maxn];
int poinv[maxn];
int po2[maxn];
int pr[2*maxn];
int cnt[26];
int pos;
string h;
int count(string s,string w)
{
    //cout<<s<<' '<<w<<endl;
    int n=s.size();int m=w.size();
    int hs1=0;
    for(int i=0;i<m;++i)
    {
        hs1*=mod;
        hs1+=(w[i]-'a');
        hs1%=p;
    }
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        pr[i+1]=pr[i]*mod+(s[i]-'a');
        pr[i+1]%=p;
    }
    int ans=0;
    for(int i=0;i<=(n-m);++i)
    {
        int hs=pr[i+m]-pr[i]*po2[m];
        hs%=p;
        hs+=p;
        hs%=p;
        if(hs==hs1) ++ans;
    }
    //cout<<ans<<" ans "<<endl;
    return ans;
}
void count1(string s,string w)
{
    //cout<<s<<' '<<w<<endl;
    int n=s.size();int m=w.size();
    int hs1=0;
    for(int i=0;i<m;++i)
    {
        hs1*=mod;
        hs1+=(w[i]-'a');
        hs1%=p;
    }
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        pr[i+1]=pr[i]*mod+(s[i]-'a');
        pr[i+1]%=p;
    }
    for(int i=0;i<=(n-m);++i)
    {
        int hs=pr[i+m]-pr[i]*po2[m];
        hs%=p;
        hs+=p;
        hs%=p;
        if(i<=pos && (i+m)>pos)
        {
        //if(i==pos) cout<<hs<<" "<<hs1<<endl;
        int j=(m+i-pos-1);
        //if(i==pos) cout<<j<<" j "<<endl;
        for(int k=0;k<26;++k)
        {
            if(((hs+po2[j]*k)%p)==hs1)
            {
                //cout<<k<<" k "<<endl;
                cnt[k]++;
            }
        }
        }
    }
    //cout<<ans<<" ans "<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    po[0]=1;
    po2[0]=1;
    poinv[0]=1;
    for(int i=1;i<maxn;++i)
    {
        po[i]=po[i-1]*2;
        po[i]%=p;
        po2[i]=po2[i-1]*mod;
        po2[i]%=p;
        poinv[i]=poinv[i-1]*inv2;
        poinv[i]%=p;
    }
    int n,q;
    cin>>n>>q;
    int n1=n;
    string s,t;
    cin>>s>>t;
    int pr[t.size()+1][26];
    for(int i=0;i<26;++i) pr[t.size()][i]=0;
    for(int i=(t.size()-1);i>=0;i--)
    {
        for(int j=0;j<26;++j)
        {
            if(t[i]!=('a'+j))
            {
                pr[i][j]=pr[i+1][j];
            }
            else
            {
                pr[i][j]=pr[i+1][j]+po[n-i-1];
                pr[i][j]%=p;
            }
        }
    }
    while(q--)
    {
        string w;int k;
        cin>>k>>w;
        n=k;
        h=s;
        int cyc=k;
        for(int i=0;i<k;++i)
        {
            if(h.size()>2*w.size())
            {
                break;
            }
            h=(h+t[i]+h);
            cyc--;
            if(h.size()>2*w.size())
            {
                break;
            }
        }
        //cout<<h<<" h "<<endl;
        int u=count(h,w);
        if(!cyc)
        {
            cout<<u<<'\n';
            continue;
        }
        //cout<<u<<" u "<<endl;
        for(int i=0;i<26;++i) cnt[i]=0;
        string f=(h+'a'+h);
        //cout<<f<<" f "<<endl;
        pos=h.size();
        count1(f,w);
        //for(int i=0;i<26;++i) cout<<cnt[i]<<' ';
        //cout<<endl;
        int bud[26];
        for(int i=0;i<26;++i)
        {
            bud[i]=(pr[n-cyc][i]-pr[n][i])*poinv[t.size()-n];
            bud[i]%=p;bud[i]+=p;bud[i]%=p;
        }
        int res=0;
        res=(u*po[cyc])%p;
        for(int i=0;i<26;++i)
        {
            res+=bud[i]*cnt[i];
            res%=p;
        }
        cout<<res<<'\n';
    }
    return 0;
}