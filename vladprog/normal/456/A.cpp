#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for(int i=1;i<n;i++)
        if(a[i].second<a[i-1].second)
            return cout<<"Happy Alex", 0;
    cout<<"Poor Alex";
}