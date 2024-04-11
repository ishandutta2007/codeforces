#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int n;

int ask(int q)
{
    q%=n;
    q+=n;
    q%=n;
    cout<<"? "<<q+1<<endl;
    int resp;
    cin>>resp;
    return resp;
}

void ans(int p)
{
    p%=n;
    p+=n;
    p%=n;
    cout<<"! "<<p+1<<endl;
    exit(0);
}

void fail()
{
    cout<<"fail"<<endl;
    cout<<(1/0);
    exit(1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>k;
    if(n<=20)
    {
        for(int i=0;i<20;i++)
            ask(0);
        for(int i=0;i<20;i++)
            if(ask(i)==k&&
               ask(i-1)<k&&
               ask(i+1)>k)
                ans(i);
        fail();
    }
    else
    {
        set<int> s;
        for(int i=0;;i++)
        {
            int q=i*(i+1);
            if(ask(q)!=k)
            {
                for(int j=q-1;j>=q-i;j--)
                    if(ask(j)==k)
                        ans(j);
                for(int j=q+1;j<=q+i;j++)
                    if(ask(j)==k)
                        ans(j);
                fail();
            }
            s.insert(q);
            if(i*(i+1)>=n)
                break;
        }
        fail();
    }
}