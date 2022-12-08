#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(!z && x==y) cout<<0<<endl;
    else if(x+z < y) cout<<"-"<<endl;
    else if(y+z < x) cout<<"+"<<endl;
    else cout<<"?"<<endl;
}