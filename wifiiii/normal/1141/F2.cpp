
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[2000], sum[2000];
multimap<int,pair<int,int> > mp;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int j=1;j<=n;++j)
        for(int i=j-1;i>=0;--i)
        {
            mp.insert({sum[j]-sum[i], {j,i+1}});
        }
    int r = -1e9, rr = -1, cnt = 0;
    int ans = 0;
    vector<pair<int,int> > vec,vans;
    for(auto it : mp)
    {
        if(it.first == r)
        {
            if(it.second.second > rr) cnt++,r=it.first,rr=it.second.first,vec.push_back({it.second.second,it.second.first});
        }
        else vec.clear(),cnt=1,r=it.first,rr=it.second.first,vec.push_back({it.second.second,it.second.first});
        if(ans < cnt)
        {
            ans = cnt;
            vans = vec;
        }
    }
    cout << ans << endl;
    for(auto p:vans) cout<<p.first<<" "<<p.second<<endl;
}