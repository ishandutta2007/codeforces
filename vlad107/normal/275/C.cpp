#include<iostream>
#include<algorithm>
#include<map>
#define F for(i=0;i<n;i++)
using namespace std;int n,k,a[1<<19],i,r,u;map<int,int>s;
int main(){cin>>n>>k;F cin>>a[i];sort(a,a+n);F if((u=a[i])%k|!s[u/k])s[u]=++r;cout<<r;}