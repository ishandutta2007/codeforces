#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    pair<string,string>a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    pair<string,string>b[n];
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        p--;
        b[i]=a[p];
        if(b[i].first>b[i].second)
            swap(b[i].first,b[i].second);
    }
    string pred="";
    for(int i=0;i<n;i++)
        if(b[i].first>pred)
            pred=b[i].first;
        else if(b[i].second>pred)
            pred=b[i].second;
        else
            cout<<"NO",exit(0);
    cout<<"YES";
}