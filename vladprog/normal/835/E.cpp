#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int n,x,y;

map<vector<int>,int> mem;

int get(int mask)
{
    vector<int> v;
    for(int i=1;i<=n;i++)
        if((i&mask)==mask)
            v.push_back(i);
    if(mem.count(v))
        return mem[v];
    cout<<"? "<<v.size()<<" ";
    for(int i:v)
        cout<<i<<" ";
    cout<<endl;
    int ans;
    cin>>ans;
    if(ans==0) ans=0;
    else if(ans==x) ans=1;
    else if(ans==y) ans=2;
    else ans=3;
    return mem[v]=ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mem[{}]=0;
    cin>>n>>x>>y;
    int p1_xor_p2=0,pos=-1;
    for(int i=0;i<10;i++)
        if(get(1<<i)&2)
            p1_xor_p2|=1<<i,
            pos=i;
    int p1=0;
    for(int i=0;i<10;i++)
        if(get((1<<i)|(1<<pos))&2)
            p1|=1<<i;
    int p2=p1^p1_xor_p2;
//    cout<<p1<<" "<<p2<<"\n";
    if(p1>p2)
        swap(p1,p2);
    cout<<"! "<<p1<<" "<<p2<<endl;
}