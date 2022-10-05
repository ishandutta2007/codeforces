#include <bits/stdc++.h> 
using namespace std;
int main()
{
    int l1,l2,r1,r2,x,y,l,r,n;
    l1=l2=r1=r2=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        if(l1==-1||l>l1)
        {
            l2=l1;
            l1=l;
            x=i;
        }
        else if(l2==-1||l>l2)
            l2=l;
 
        if(r1==-1||r<r1)
        {
            r2=r1;
            r1=r;
            y=i;
        }
        else if(r2==-1||r<r2)
            r2=r;
    }
    if(x==y) cout<<max(0,r2-l2);
    else     cout<<max(0,max(r2-l1,r1-l2));
    return 0;
}