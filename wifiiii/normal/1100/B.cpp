#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
int a[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    for(int i=1;i<=m;++i)
    {
        int cur; cin >> cur;
        if(a[cur]==0) cnt++;
        a[cur]++;
        if(cnt==n)
        {
            cout<<1;
            for(int i=1;i<=n;++i)
            {
                a[i]--;
                if(a[i]==0) cnt--;
            }
        } else cout<<0;
    }
    cout<<endl;
}