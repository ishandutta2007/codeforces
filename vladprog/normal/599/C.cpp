#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef map<pii,int> mpi;
typedef mpi::iterator it;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    mpi m;
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        a[i]=c;
        m.insert(mp(mp(c,i),0));
    }
    for(pair<it,int>i=mp(m.begin(),1);
        i.first!=m.end();
        i.first++,i.second++)
        i.first->second=i.second;
    int k=0;
    for(int i=1,c=0,r=0;i<=n;i++)
    {
        c++;
        r=max(r,m[mp(a[i],i)]);
        if(c==r)k++;
    }
    printf("%d",k);
}