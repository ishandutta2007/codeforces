#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[200005];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(m==n*(n-1)/2) {cout<<"NO\n";return 0;}
    int i;
    for(i=1;i<=n;++i) if(v[i].size()<n-1) break;
    v[i].push_back(i);
    sort(v[i].begin(),v[i].end());
    int p=i,q;
    for(int j=0;j<n;++j)
    {
        if(v[i].size()<=j || v[i][j]!=j+1) {q=j+1;break;}
    }
    cout << "YES\n";
    int j = 3;
    for(int i=1;i<=n;++i)
    {
        if(i>1) cout <<" ";
        if(i==p) cout<<1;
        else if(i==q) cout<<2;
        else cout<<j++;
    }
    cout << endl;
    j = 3;
    for(int i=1;i<=n;++i)
    {
        if(i>1) cout <<" ";
        if(i==p) cout<<1;
        else if(i==q) cout<<1;
        else cout<<j++;
    }
    cout << endl;
}