
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

struct node
{
    int a,b,d;
};
struct stone
{
    int v,id;
    bool operator < (const stone & s) const
    {
        return v<s.v;
    }
}a[300005],b[300005];
pair<int,int> save[1000005];
vector<node> as;
int tot = 0, now = 1;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll tmp = 0;
    rep(i,n)
    {
        cin>>a[i].v;
        a[i].id=i;
        tmp+=a[i].v;
    }
    rep(i,n)
    {
        cin>>b[i].v;
        b[i].id=i;
        tmp-=b[i].v;
    }
    if(tmp)
    {
        cout << "NO"<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    ll cur = 0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]<b[i])
        {
            save[++tot] = {a[i].id,b[i].v-a[i].v};
            cur+=b[i].v-a[i].v;
        }
        else if(a[i].v>b[i].v)
        {
            if(b[i].v-a[i].v+cur<0) {cout<<"NO"<<endl;return 0;}
            cur += b[i].v-a[i].v;
            int tmp = a[i].v-b[i].v;
            while(tmp)
            {
                if(tmp <= save[now].second)
                {
                    save[now].second -= tmp, as.push_back(node{save[now].first,a[i].id,tmp});
                    if(!save[now].second) now++;
                    break;
                }
                else
                {
                    as.push_back(node{save[now].first,a[i].id,save[now].second});
                    tmp -= save[now].second;
                    now++;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<as.size()<<endl;
    for(node n:as) cout<<n.a<<" "<<n.b<<" "<<n.d<<endl;
}