#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
const ll mod=1e9+7;
int arr[maxn],n;
int father[maxn];

int find(int a)
{
    if(father[a]==a)return a;
    return father[a]=find(father[a]);
}

bool solve()
{
//    for(int i=1;i<=2*n;i++)
//        cout<<arr[i]<<' ';
//    cout<<endl;
    set<int>s;
    vector<int>v;
    for(int i=1;i<=n*2;i++)
    {
        int x=arr[i];
        if(!s.count(x))
        {
            v.push_back(x);
            s.insert(x);
        }
        else
        {
            s.erase(x);
            int en=v.size()-1;
            while(1)
            {
                int y=v[en];
                if(y==x)
                {
                    v.erase(v.begin()+en);
                    break;
                }
                int fx=find(x),fy=find(y);
                if(fx==fy)return 0;
                father[fx]=fy;
                en--;
            }
        }
    }
    for(int i=2;i<=n;i++)
        if(find(i)!=find(i-1))return 0;
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)father[i]=i;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a]=arr[b]=i;
    }
    if(solve())puts("YES");
    else puts("NO");
    return 0;
}