#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
typedef long long ll;
const ll mod=1e18+7;
ll qpow(ll a, ll n, ll p=mod)
{
    ll re = 1;
    while(n)
    {
        if(n & 1)
            re = (re * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return re % p;
}

ll C(ll n, ll m)
{
    if(n==m||m==0)
    {
        return 1;
    }
    else
    {
        return C(n-1, m)+C(n-1, m-1);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        ll m=2;
        v.clear();
        while(n)
        {
            v.push_back(n%m);
            n/=m;
            m++;
        }

        sort(v.begin(), v.end());
        if(v[0]==0)
        {

            int cnt=1;
            reverse(v.begin(), v.end());
            int nn=v.size()+1;
            ll res=1, res1=1;

            for(int i=0; i<v.size(); i++)
            {
                if(v[i]==0) break;
                if(v[i]==v[i+1])
                {
                    cnt++;
                }
                else
                {
                    res*=C(nn-v[i], cnt);
                    if(nn-1-v[i]<cnt)
                    {
                        res1=0;
                    }
                    else
                    {
                        res1*=C(nn-1-v[i], cnt);
                    }
                    nn-=cnt;
                    cnt=1;
                }
            }
            printf("%lld\n", res-res1-1);
        }
        else
        {
            int cnt=1;
            reverse(v.begin(), v.end());
            int nn=v.size()+1;
            ll res=1;

            for(int i=0; i<v.size()-1; i++)
            {
                if(v[i]==0) break;
                if(v[i]==v[i+1])
                {
                    cnt++;
                }
                else
                {
                    res*=C(nn-v[i], cnt);
                    nn-=cnt;
                    cnt=1;
                }
            }
            res*=C(nn-v[v.size()-1], cnt);
            printf("%lld\n", res-1);
        }

    }

}