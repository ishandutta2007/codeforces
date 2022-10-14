#include <bits/stdc++.h>
#define BT 10
using namespace std;

int n,x,y;
bool dif[BT];
int ask(vector <int> v)
{
        if(v.empty()) return 0;
        printf("? %d ",v.size());
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
        printf("\n");
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        return ret;
}
int main()
{
        scanf("%d %d %d",&n,&x,&y);
        for(int i=0;i<BT;i++)
        {
                vector <int> p;
                for(int j=1;j<=n;j++) if(j>>i&1) p.push_back(j);
                int v=ask(p);
                if(v!=0&&v!=x) dif[i]=true;
        }
        int id1=0,id2=0;
        for(int i=0;i<BT;i++)
        {
                if(!dif[i]) continue;
                vector <int> p;
                for(int j=1;j<=n;j++) if(j>>i&1) p.push_back(j);
                assert(!p.empty());
                int l=0,r=p.size()-1,pos=0;
                while(l<=r)
                {
                        int m=(l+r)/2;
                        vector <int> qv;
                        for(int j=0;j<=m;j++) qv.push_back(p[j]);
                        int val=ask(qv);
                        if(val!=0&&val!=x) pos=m,r=m-1;
                        else l=m+1;
                }
                id1=p[pos];
                break;
        }
        for(int i=0;i<BT;i++)
        {
                if(dif[i])
                {
                        if(!(id1&(1<<i))) id2+=(1<<i);
                }
                else
                {
                        if(id1&(1<<i)) id2+=(1<<i);
                }
        }
        if(id1>id2) swap(id1,id2);
        printf("! %d %d",id1,id2);
        fflush(stdout);
        return 0;
}