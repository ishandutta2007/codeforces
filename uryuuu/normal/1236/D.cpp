#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<queue>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int n,m,k;
set<int>col[maxn],row[maxn];
bool del(int up,int down,int left,int right)
{
    for(int i=up;i<=down;i++)
    {
        for(int j=left;j<=right;j++)
        {
            if(row[i].find(j)==row[i].end())
                return 0;
            row[i].erase(j);
            col[j].erase(i);
            k--;
        }
    }
    return 1;
}

void run()
{
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        col[y].insert(x);
        row[x].insert(y);
    }
    int d=0;
    int up=1,down=n,left=1,right=m;
    int dd=0;
    int x=1,y=1;
    while(k)
    {
        if(d==0)
        {
            auto it=row[x].begin();
            if(it==row[x].end())
                y=right;
            else
            {
                int p=*it;
                if(!del(up,down,p,right))
                {
                    cout<<"No"<<endl;
                    return ;
                }
                right=y=p-1;
            }
            left+=dd;
        }
        else if(d==1)
        {
            auto it =col[y].begin();
            if(it==col[y].end())
                x=down;
            else
            {
                int p=*it;
                if(!del(p,down,left,right))
                {
                    cout<<"No"<<endl;
                    return ;
                }
                down=x=p-1;
            }
            up+=dd;
        }
        else if(d==2)
        {
            auto it =row[x].rbegin();
            if(it==row[x].rend())
                y=left;
            else
            {
                int p=*it;
                if(!del(up,down,left,p))
                {
                    cout<<"No"<<endl;
                    return ;
                }
                left=y=p+1;
            }
            right-=dd;
        }
        else
        {
            auto it =col[y].rbegin();
            if(it==col[y].rend())
                x=up;
            else
            {
                int p=*it;
                if(!del(up,p,left,right))
                {
                    cout<<"No"<<endl;
                    return ;
                }
                up=x=p+1;
            }
            down-=dd;
        }
        d=(d+1)%4;
        dd=1;
    }
    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m>>k)
    {
        run();
    }
    return 0;
}