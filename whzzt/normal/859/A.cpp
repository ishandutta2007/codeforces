#include<bits/stdc++.h>
using namespace std;
int n,mx,m;int main(){cin>>n;while(n--)cin>>m,mx=max(mx,m);cout<<max(mx-25,0);}