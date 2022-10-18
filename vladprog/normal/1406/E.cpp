#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}

int A(int a)
{
    cout<<"A "<<a<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int B(int a)
{
    cout<<"B "<<a<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int C(int a)
{
    cout<<"C "<<a<<endl;
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> p;
    for(int i=2;i<=n;i++)
        if(prime(i))
            p.push_back(i);
    int x=1,sz=n;
    for(int i=0;i<p.size();i+=100)
    {
        for(int j=i;j<min<int>(p.size(),i+100);j++)
            sz-=B(p[j]);
        int now=A(1);
        if(now!=sz)
        {
            for(int j=i;j<min<int>(p.size(),i+100);j++)
            {
                int cur=A(p[j]);
                if(cur)
                {
                    sz++;
                    x*=p[j];
                    for(int pw=p[j]*p[j];pw<=n;pw*=p[j])
                        if(A(pw))
                            x*=p[j];
                        else
                            break;
                }
            }
        }
    }
    C(x);
}