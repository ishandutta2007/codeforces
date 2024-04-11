#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int n,q;cin>>n>>q;
    set<int>s;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        s.insert(a);
    }
    int last=0;
    for(auto i:s)
    {
        if(i!=*s.begin())
        {
            mp[i-last]++;
        }
        last=i;
    }
    if(s.size()<=2)cout<<0<<endl;
    else cout<<*(--s.end())-*s.begin()-(--mp.end())->x<<endl;
    while(q--)
    {
        int op,p;cin>>op>>p;
        if(op==1)
        {
            if(s.empty())
            {
                s.insert(p);
            }
            else if(p<*s.begin())
            {
                mp[*s.begin()-p]++;
                s.insert(p);
            }
            else if(p>*(--s.end()))
            {
                mp[p-*(--s.end())]++;
                s.insert(p);
            }
            else
            {
                auto a=s.lower_bound(p);
                auto b=a;
                b--;
                int len=*a-*b;
                mp[len]--;
                if(mp[len]==0)mp.erase(len);
                mp[p-*b]++;
                mp[*a-p]++;
                s.insert(p);
            }
        }
        else
        {
            if(s.size()==1)
            {
                s.erase(p);
            }
            else if(p==*s.begin())
            {
                s.erase(p);
                int tmp=*s.begin()-p;
                mp[tmp]--;
                if(mp[tmp]==0)mp.erase(tmp);
            }
            else if(p==*(--s.end()))
            {
                s.erase(p);
                int tmp=p-*(--s.end());
                mp[tmp]--;
                if(mp[tmp]==0)mp.erase(tmp);
            }
            else
            {
                s.erase(p);
                auto a=s.lower_bound(p);
                auto b=a;
                b--;
                int len=*a-*b;
                mp[len]++;
                int tmp=*a-p;
                mp[tmp]--;
                if(mp[tmp]==0)mp.erase(tmp);
                tmp=p-*b;
                mp[tmp]--;
                if(mp[tmp]==0)mp.erase(tmp);
            }
        }
        if(s.size()<=2)cout<<0<<endl;
        else cout<<*(--s.end())-*s.begin()-(--mp.end())->x<<endl;
//        cout<<*(--s.end())<<' '<<*s.begin()<<' '<<(--mp.end())->x<<endl;

    }
    return 0;
}