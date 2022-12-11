#include <iostream>

using namespace std;

int main()
{
    int n,i,a[100001],h[5001],tmp;
    cin>>n;
    int m=0;
    for(i=0;i<n;i++){cin>>tmp;h[tmp]++;if (m<tmp) m=tmp;}
    int ans=0;
    for(i=1;i<=m;i++) if (h[i]) {ans++;a[ans]=i;h[i]--;}
    for(i=m-1;i>0;i--) if (h[i]) {ans++;a[ans]=i;}
    cout<<ans<<endl;
    for(i=1;i<=ans;i++) cout<<a[i]<<" ";
}