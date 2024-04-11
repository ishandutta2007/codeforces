#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;
int main()
{
    int n,x,y,a[1010];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
	int m=INF;
    for(int i=0;i<n-1;i++)
    {
        if(abs(a[i]-a[i+1])<m)
        {
            m=abs(a[i]-a[i+1]);
            x=i+1;
            y=i+2;
        }
    }
    if(abs(a[n-1]-a[0])<m)
    {
        x=n;
        y=1;
    }
    cout<<x<<" "<<y;
    return 0;
}