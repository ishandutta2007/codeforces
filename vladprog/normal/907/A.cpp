#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v1,v2,v3,vm;
    cin>>v1>>v2>>v3>>vm;
    int l1=max(v1,vm*2+1),r1=2*v1,
        l2=max(v2,vm*2+1),r2=min(2*v2,r1-1),
        l3=max(v3,vm),r3=min({2*v3,2*vm,r2-1});
    if(l1<=r1&&l2<=r2&&l3<=r3)
        cout<<r1<<" "<<r2<<" "<<r3;
    else
        cout<<-1;
}