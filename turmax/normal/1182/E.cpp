#include <bits/stdc++.h>

using namespace std;
#define int long long
int p;
struct matrix
{
    int n;
    vector <vector<int> > a;
};
matrix operator*(matrix a,matrix b)
{
    int n=a.n;
    matrix c;
    vector <vector<int> > v1;
    vector <vector<int> > v2;
    v1=a.a;
    v2=b.a;
    c.n=a.n;
    vector <vector<int> > u(c.n);
    for(int i=0;i<u.size();++i)
    {
        for(int j=0;j<u.size();++j)
        {
            u[i].push_back(0);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                u[i][j]+=(v1[i][k]*v2[k][j]);
                u[i][j]%=p;
            }
        }
    }
    c.a=u;
    return c;
}
matrix po(matrix a,int n)
{
     if(n==1)
     {
         return a;
     }
     if(n%2==1)
     {
         return po(a,n-1)*a;
     }
     if(n%2==0)
     {
         matrix u;
         u=po(a,n/2);
         return u*u;
     }
}
int linearrecurrent(int n,vector <int> a,vector <int> rec,int z,int r)
{
    p=r;
    matrix b;
    b.n=n;
    vector <vector<int> > v(n);
    for(int i=0;i<(n-1);++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j==(i+1))
            {
                v[i].push_back(1);
            }
            else
            {
                v[i].push_back(0);
            }
        }
    }
    v[n-1]=rec;
    b.a=v;
    matrix c=po(b,z);
    vector <vector<int> > g;
    g=c.a;
    int s=0;
    for(int i=0;i<n;++i)
    {
        s+=(a[i]*(g[0][i]));
        s%=p;
    }
    return s;
}
int modpo(int x,int n,int p1)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return (x%p1);
    }
    else if(n%2==0)
    {
        int u=modpo(x,n/2,p1);
        return (u*u)%p1;
    }
    else
    {
        int u=modpo(x,n-1,p1);
        return (u*x)%p1;
    }
}
int32_t main()
{
    int n,z,b,c,d;
    cin>>n>>z>>b>>c>>d;
    int u1,u2,u3,u4;
    vector <int> rec;
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    vector <int> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    u1=linearrecurrent(3,a,rec,n-1,1e9+6);
    rec.clear();
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    a.clear();
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    u2=linearrecurrent(3,a,rec,n-1,1e9+6);
    rec.clear();
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    u3=linearrecurrent(3,a,rec,n-1,1e9+6);
    rec.clear();
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    a.clear();
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    u4=((linearrecurrent(3,a,rec,n-1,1e9+6)-n)%(1000000000+6)+1000000000+6)%(1000000000+6);
    cout<<(((modpo(z,u1,1000000000+7)*modpo(b,u2,1000000000+7))%(1000000000+7))*((modpo(c,u3,1000000000+7)*modpo(d,u4,1000000000+7))%(1000000000+7)))%(1000000000+7);
    return 0;
}