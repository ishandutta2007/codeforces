
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[300005],head=1,tail=1;
pair<int,int> ans[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    forii
    {
        int tmp;cin>>tmp;
        a[tail++]=tmp;
    }
    int Mi=-1,Mx=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>Mx) Mx=a[i],Mi=i;
    }
    for(int i=1;i<Mi;++i)
    {
        //for(int i=head;i<tail;++i) cout<<a[i]<<" ";cout<<endl;
        int t1=a[head],t2=a[head+1];
        ans[i]={t1,t2};
        if(t1>t2) swap(a[head],a[head+1]);
        a[tail++]=a[head];++head;
    }
    //for(int i=head;i<tail;++i) cout<<a[i]<<" ";cout<<endl;
    while(q--)
    {
        ll t;
        cin>>t;
        if(t<Mi) cout<<ans[t].first<<" "<<ans[t].second<<"\n";
        else if(t>=Mi)
        {
            cout<<a[head]<<" "<<a[head+1+(t-Mi)%(n-1)]<<"\n";
        }
    }
}