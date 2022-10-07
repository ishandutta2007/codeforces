#include <bits/stdc++.h>
#define N 2005
#define f first
#define s second
using namespace std;
long long l1,r1,l2,r2,k,ans;
int main()
{
cin>>l1>>r1>>l2>>r2>>k;
if (l1>l2){swap(l1,l2);swap(r1,r2);}
if (r1>r2){
    ans=r2-l2+1;
    if (k>=l2 && k<=r2)ans--;
}
else if (l2<=r1){
    ans=r1-l2+1;
    if (k>=l2 && k<=r1)ans--;
}
cout<<ans<<endl;
return 0;
}