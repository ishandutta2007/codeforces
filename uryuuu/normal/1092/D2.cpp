#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
int a[200005];
stack<int>b;
int main()
{
    int n,d=-999;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        d=max(d,a[i]);
    }
    if(a[0]<a[1]||a[n-1]<a[n-2])
        cout<<"NO"<<endl;
    else
    {
    for(int i=0;i<n;i++)
        if(b.empty())
    b.push(a[i]);
    else
    {
        if(b.top()<a[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(b.top()==a[i])
            b.pop();
        else
        b.push(a[i]);
    }
    if(b.size()>1)
        cout<<"NO"<<endl;
        else if(!b.empty()&&b.top()!=d)
            cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    }
    return 0;
}