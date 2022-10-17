#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
struct point
{
    int first, second;
    int idx;
    bool operator < (point const & p) const
    {
        if(first==p.first) return second<p.second;
        return first<p.first;
    }
};
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
point a[200005];
int ans[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i) ans[i]=-1;
        priority_queue<pii,vector<pii>,greater<pii> > s;
        for(int i=1;i<=n;++i) {cin>>a[i].first>>a[i].second;a[i].idx=i;}
        sort(a+1,a+1+n);
        int ok = 0;
        int init = 0;
        for(int i=1;i<=n;++i)
        {
            int temp;
            while(!s.empty())
            {
                temp = s.top().first;
                if(temp<a[i].first) s.pop();
                else break;
            }
            s.push({a[i].second,a[i].idx});
            if(s.size()>1)
            {
                pii top1 = s.top();s.pop();
                pii top2 = s.top();
                if(ans[top1.second] != -1) ans[a[i].idx] = ans[top1.second];
                else ans[a[i].idx] = ans[top2.second];
                s.push(top1);
            }
            else if(s.size()==1)
            {
                pii top1 = s.top();
                if (!init) ans[top1.second] = 1, init = 1;
                else ans[top1.second] = 2;
            }
        }
        for(int i=1;i<n;++i) if(ans[i]!=ans[i+1]) {ok=1;break;}
        if(!ok) cout<<-1<<endl;
        else
        {
            for(int i=1;i<=n;++i)
            {
                if(i!=1) cout<<" ";
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
}