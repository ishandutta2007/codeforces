#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+1000;
const ll mod=1e9+7;
const double PI=acos(0)*2;

bool vis[maxn];
int prm[maxn];
int n;

int solve()
{
    int ret=1;
    for(int i=0;i<70;i++)
    {
        if(prm[i]>n)return ret;
        int a;
        cout<<"B "<<prm[i]<<endl;
        cin>>a;
        cout<<"A "<<prm[i]<<endl;
        cin>>a;
        if(a)
        {
            ret*=prm[i];
            a=prm[i]*prm[i];
            while(a<=n)
            {
                cout<<"A "<<a<<endl;
                int b;cin>>b;
                if(b)ret*=prm[i];
                else break;
                a*=prm[i];
            }
        }
    }
    if(ret!=1)
    {
        for(int i=70;;i++)
        {
            if(prm[i]*ret>n)return ret;
            cout<<"A "<<prm[i]*ret<<endl;
            int a;cin>>a;
            if(a)return ret*prm[i];
        }
    }
    int last,l=70;
    cout<<"A 1"<<endl;
    cin>>last;
    while(1)
    {
        for(int i=l;;i++)
        {
            if(prm[i]>n||i==l+100)
            {
                int tmp;
                cout<<"A 1"<<endl;
                cin>>tmp;
                if(last-tmp!=i-l)
                {
                    for(int j=l;j<i;j++)
                    {
                        cout<<"A "<<prm[j]<<endl;
                        int a;cin>>a;
                        if(a)return prm[j]*ret;
                    }
                }
                if(prm[i]>n)return ret;
                l=i;
                last=tmp;
                break;
            }
            else
            {
                cout<<"B "<<prm[i]<<endl;
                int a;cin>>a;
            }

        }
    }
}

int main()
{
    cin>>n;
    for(int i=2;i*i<maxn;i++)if(!vis[i])
        for(int j=i*2;j<maxn;j+=i)vis[j]=1;
    int num=0;
    for(int i=2;i<maxn;i++)if(!vis[i])
    {
        prm[num++]=i;
    }
    int ans=solve();
    cout<<"C "<<ans<<endl;
    return 0;
}