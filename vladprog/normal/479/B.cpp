#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    set< pair<int,int> > b;
    vector< pair<int,int> > v;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        b.insert(make_pair(a,i));
    }
    for(int i=1;i<=k;i++)
    {
        set< pair<int,int> >::iterator
            il=b.begin(),
            ir=b.end();
        ir--;
        pair<int,int> l=*il,r=*ir;
        if(l.first==r.first)
            break;
        b.erase(il);
        b.erase(ir);
        v.push_back(make_pair(r.second,l.second));
        l.first++;
        r.first--;
        b.insert(l);
        b.insert(r);
    }
    set< pair<int,int> >::iterator
        l=b.begin(),
        r=b.end();
    r--;
    int s=r->first-l->first;
    printf("%d %d\n",s,v.size());
    for(int i=0;i<v.size();i++)
        printf("%d %d\n",v[i].first,v[i].second);
}