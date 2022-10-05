#include<bits/stdc++.h>
using namespace std;
const int MAXN=510; 
int n,k,c,a[MAXN],ans=0;
int main()
{
    cin>>n>>k>>c;
    for(int i=1;i<=c;i++){
        cin>>a[i];
        ans+=(a[i]-a[i-1]-1)/k;
    }
    ans+=c+(n-a[c])/k;
    cout<<ans<<endl;
    return 0;
}