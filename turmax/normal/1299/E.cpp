#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3*5*7*8;
int ans[maxn];
int pos[maxn];
int c[maxn][9];
map <vector <int>,int> u;
int n;
int query(vector <int> v)
{
    if(v.size()==1) return 1;
    cout<<"? "<<v.size()<<' ';
    //int sum=0;
    for(auto h:v) cout<<h+1<<' ';
    cout<<endl;
    int res;
    cin>>res;
    return res;
}
void go(int mod)
{
    for(int i=0;i<n;++i)
    {
        if(ans[i]!=(-1))
        {
            c[i][mod]=(ans[i]%mod);
            continue;
        }
        //cout<<i<<" i "<<" check "<<endl;
        vector <int> z1;z1.clear();
        for(int j=0;j<mod;++j)
        {
            z1.push_back(j);
        }
        shuffle(z1.begin(),z1.end(),default_random_engine(getpid()));
        for(auto h:z1)
        {
            if(h==z1.back()) {c[i][mod]=h;continue;}
            vector <int> v;
            if(mod==8)
            {
                if(pos[u[{c[i][3],c[i][5],c[i][7],h}]]!=(-1))
                {
                    continue;
                }
            }
            if(mod%2==1)
            {
            for(int j=1;j<=mod;++j)
            {
                if((j%mod)!=h)
                {
                    v.push_back(pos[j]);
                }
            }
            }
            else
            {
            for(int j=1;j<=mod;++j)
            {
                if(((j+mod/2)%mod)!=h)
                {
                    v.push_back(pos[j]);
                }
            }
            }
            v.push_back(i);
            if(query(v))
            {
                c[i][mod]=h;
                break;
            }
        }
        if(mod==8)
        {
             ans[i]=u[{c[i][3],c[i][5],c[i][7],c[i][8]}];
             pos[ans[i]]=i;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) pos[i]=(-1);
    for(int i=0;i<maxn;++i)
    {
        u[{i%3,i%5,i%7,i%8}]=i;
    }
    for(int i=0;i<maxn;++i) ans[i]=(-1);
    cin>>n;
    bool h=false;
    vector <int> v;
    vector <int> z;
    for(int i=0;i<n;++i) z.push_back(i);
    shuffle(z.begin(),z.end(),default_random_engine(getpid()));
    for(auto i:z)
    {
         v.clear();
         for(int j=0;j<n;++j)
         {
             if(i!=j)
             {
                 v.push_back(j);
             }
         }
         if(query(v))
         {
             if(!h)
             {
                 ans[i]=1;
                 pos[1]=i;
                 h=true;
             }
             else
             {
                 ans[i]=n;
                 pos[n]=i;
                 break;
             }
         }
    }
    for(int i=2;i<min(n,9LL);++i)
    {
        /*cout<<" ans "<<endl;
        for(int j=0;j<n;++j)
        {
            cout<<ans[j]<<' ';
        }
        cout<<endl;
        cout<<i<<" i "<<endl;*/
        shuffle(z.begin(),z.end(),default_random_engine(getpid()));
        if(i%2==0)
        {
        for(auto j:z)
        {
            //cout<<j<<" j "<<endl;
            if(ans[j]==(-1))
            {
                v.clear();
                for(int k=0;k<n;++k)
                {
                    if(k!=j && (ans[k]==(-1)))
                    {
                        v.push_back(k);
                    }
                }
                if(query(v))
                {
                    //cout<<" gtfrd "<<endl;
                    if(query({j,pos[n]}))
                    {
                    ans[j]=i;
                    pos[i]=j;
                    //cout<<i<<" pos[i] "<<j<<endl;
                    break;
                    }
                }
            }
        }
        }
        else
        {
        for(auto j:z)
        {
            //cout<<j<<" j "<<endl;
            if(ans[j]==(-1))
            {
                v.clear();
                for(int k=0;k<n;++k)
                {
                    if(k!=j && (ans[k]==(-1) || ans[k]==n))
                    {
                        v.push_back(k);
                    }
                }
                if(query(v))
                {
                    ans[j]=i;
                    pos[i]=j;
                    //cout<<i<<" pos[i] "<<j<<endl;
                    break;
                }
            }
        }
        }
    }
    go(3);go(5);go(7);go(8);
    for(int i=0;i<n;++i)
    {
        ans[i]=u[{c[i][3],c[i][5],c[i][7],c[i][8]}];
    }
    if(ans[0]>(n/2))
    {
        for(int i=0;i<n;++i)
        {
            ans[i]=(n+1-ans[i]);
        }
    }
    cout<<"! ";
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}