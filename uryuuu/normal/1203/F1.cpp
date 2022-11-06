#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 500010
using namespace std;
struct node
{
    int a,b;
}s[105];
bool cmp(node s1,node s2)
{
    return s1.b>s2.b;
}
bool ccc(node s1,node s2)
{
    if(s1.a+s1.b==s2.a+s2.b)
        return s1.a>s2.a;
    return s1.a+s1.b>s2.a+s2.b;
}
vector<pair<int,int>>v1,v2;
int main()
{
    sync
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].b;
    }
    sort(s,s+n,cmp);
    int id=n;
    for(int i=0;i<n;i++)
    {
        if(s[i].b<0)
        {
            id=i;
            break;
        }
    }
    for(int i=0;i<id;i++)
        v1.push_back(make_pair(s[i].a,s[i].b));
    //    for(int i=0;i<(int)v1.size();i++)
    //    {
    //        cout<<v1[i].first<<' '<<v1[i].second<<' ';
    //    }
    for(int j=0;j<id;j++)
    {
        for(int i=0;i<(int)v1.size();i++)
        {
            if(r>=v1[i].first)
            {
                r+=v1[i].second;
                //                cout<<"cg"<<endl;
            }
            else
                v2.push_back(make_pair(v1[i].first,v1[i].second));
        }
        v1.clear();
        for(int i=0;i<(int)v2.size();i++)
        {
            v1.push_back(make_pair(v2[i].first,v2[i].second));
        }
        v2.clear();
    }
    if(v1.size()!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(id==n)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    sort(s+id,s+n,ccc);
    for(int i=id;i<n;i++)
    {
        if(r<s[i].a)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        r+=s[i].b;
        if(r<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}