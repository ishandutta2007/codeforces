#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

struct A
{
    int a,b;
};

bool f(int n,string x,string y)
{
    int tong[30]={0};
    for(int i=0;i<n;i++)
    {
        tong[x[i]-'a']++;
        tong[y[i]-'a']++;
    }
    for(int i=0;i<30;i++)
    {
        if(tong[i]&1)return 1;
    }

    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        string x,y;
        cin>>n>>x>>y;
        if(f(n,x,y))
        {
            puts("No");
            continue;
        }
        vector<A>v;
        for(int i=0;i<n;i++)
        {
            if(x[i]!=y[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(x[i]==x[j])
                    {
                        swap(x[j],y[i]);
                        v.push_back((A){j,i});
                        break;
                    }
                }
                if(x[i]!=y[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(x[i]==y[j])
                        {
                            swap(x[j],y[j]);
                            v.push_back((A){j,j});
                        }
                    }
                    i--;
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].a+1<<' '<<v[i].b+1<<endl;
        }

    }
}