#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#define PRT(be,en) cout<<#be<<" : "; for(auto it=be;it!=en;it++) cout<<*it<<" ";cout<<"\n";
#define PRTX(be,en) cout<<#be<<".first : "; for(auto it=be;it!=en;it++) cout<<it->first<<" ";cout<<"\n";
#define PRTY(be,en) cout<<#be<<".second : "; for(auto it=be;it!=en;it++) cout<<it->second<<" ";cout<<"\n";

using namespace std;

const int MOD=1e9+7;
const int N=5010;
const int L=13;

pair<string,int> sf[N];
int lcp[N],ptr[N],st[N][L],
    dp[N][N],sum[N][N],next1[N];

int get_min(int l,int r)
{
    if(l>r)
        swap(l,r);
    r--;
    int lg=0;
    while((1<<(lg+1))<=r-l+1)
        lg++;
    int res=min(st[l][lg],st[r-(1<<lg)+1][lg]);
    //cout<<"min "<<l<<" "<<r<<" = "<<res<<"\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    next1[n-1]=n;
    for(int i=n-1;i>=0;i--)
        if(s[i]=='0')
            next1[i]=next1[i+1];
        else
            next1[i]=i;
    for(int i=0;i<n;i++)
        sf[i]={s.substr(i),i};
    sort(sf,sf+n);
    for(int i=0;i<n;i++)
        ptr[sf[i].second]=i;
    for(int i=0;i<n-1;i++)
    {
        while(sf[i].first.size()>lcp[i]&&
              sf[i+1].first.size()>lcp[i]&&
              sf[i].first[lcp[i]]==sf[i+1].first[lcp[i]])
            lcp[i]++;
    }
    for(int i=0;i<n-1;i++)
        st[i][0]=lcp[i];
    for(int j=1;(1<<j)<=n-1;j++)
        for(int i=0;i+(1<<j)-1<n-1;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
//    PRT(lcp,lcp+n);
//    PRT(ptr,ptr+n);
//    PRTX(sf,sf+n);
//    PRTY(sf,sf+n);
    for(int r=0;r<n;r++)
        for(int l=r;l>=0;l--)
            if(s[l]=='0')
                sum[l][r]=sum[l+1][r]/*,
                cout<<l<<" "<<r<<" -> "<<dp[l][r]<<"\n"*/;
            else if(l==0)
                dp[l][r]=1,
                sum[l][r]=(sum[l+1][r]+1)%MOD/*,
                cout<<l<<" "<<r<<" -> "<<dp[l][r]<<"\n"*/;
            else
            {
                int r1=l-1,
                    l1=r1-(r-l);
                if(l1<0)
                    dp[l][r]=sum[0][r1];
                else
                {
                    int p=get_min(ptr[l1],ptr[l]);
                    //cout<<"p = "<<p<<"\n";
                    if(p>=r-l+1||s[l1+p]>s[l+p])
                        l1++;
                    l1=next1[l1];
                    dp[l][r]=sum[l1][r1];
                }
                sum[l][r]=(sum[l+1][r]+dp[l][r])%MOD;
                //cout<<l<<" "<<r<<" -> "<<dp[l][r]<<"\n";
            }
    cout<<sum[0][n-1];
}