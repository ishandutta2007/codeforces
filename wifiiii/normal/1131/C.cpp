#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

int a[105];
vector<int> ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i+=2) ans.pb(a[i]);
    reverse(ans.begin(),ans.end());
    for(int i=2;i<=n;i+=2) ans.pb(a[i]);
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
}