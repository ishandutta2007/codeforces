#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int a[100005];
set<int,greater<int>> s;
int main()
{
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    s.insert(n);s.insert(1);
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0) {s.insert(i);s.insert(n/i);}
    }
    int j = s.size();
    int cnt = 0;
    for(auto k:s)
    {
        if(cnt++) cout<<" ";
        cout<<(2+n)*(n/k+1)/2-n-1;
    }
    cout<<endl;
}