#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int n,k,t;
    cin>>n>>k;
    set<int> s;
    for(int i=1;i<=n;++i) {cin>>t;s.insert(t);}
    auto it = s.begin(), it2 = s.begin();
    cout<<*it<<endl;
    it++;
    for(int i=1;i<k;++i)
    {
        if(it==s.end()){cout<<0<<endl;continue;}
        cout<<*it-*it2<<endl;
        ++it,++it2;
    }
}