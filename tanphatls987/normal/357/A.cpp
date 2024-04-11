#include <iostream>

using namespace std;

int main()
{
    int i,n,a[200],x,y,a1,a2;
    cin>>n;
    a2=0;a1=0;
    for(i=1;i<=n;i++) {cin>>a[i];a2+=a[i];}
    cin>>x>>y;
    if ((a2>=2*x)&&(a2<=2*y))
    {
        for(i=2;i<=n;i++) {a2-=a[i-1];a1+=a[i-1];if ((a1>=x)&&(a1<=y)&&(a2<=y)&&(a2>=x)) {cout<<i;return 0;}}
    }
    cout<<0;
}