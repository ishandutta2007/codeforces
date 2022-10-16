#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
void printarray(int a[], int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void printvector(vector<int> v)
{
    for (auto x : v)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    int n,l,k;
    cin>>n>>l>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int cnt[26]={0};
    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]-'a']++;
    }
    //for(int i=0;i<26;i++) cout<<cnt[i]<<" ";
    vector<string> v(n+1);
    int t=1;
    int i=0;
    int coun=0;
    //cout<<k;
    while(v[k].size()!=l)
    {
        if(cnt[i]>k-t)
        {
            //cout<<1<<endl;
            for(int j=t;j<=k;j++)
            {
                char c=(i+'a');
                v[j]+=c;
            }
            coun+=k-t+1;
            cnt[i]=cnt[i]-(k-t+1);
        }
        else
        {
            for(int j=t;j<cnt[i]+t;j++)
            {
                char c=(i+'a');
                v[j]+=c;
                
            }
            coun+=cnt[i];
            t+=cnt[i];
            cnt[i]=0;
            i++;
        }
    }
    for(i=1;i<=n;i++)
    {
        while(v[i].size()<l)
        {
            v[i]+=s[coun];
            coun++;
        }
    }
    for(i=1;i<n+1;i++)
    {
        cout<<v[i]<<"\n";
    }
    
}