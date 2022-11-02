#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#define N 500500

using namespace std;

struct Point{
        set<pair<int,int> > ts;
        map<int,int> kt;
        int add;
        Point(){
                add=0;
                ts.clear();
                kt.clear();
        }
};

int n,pr,pred[N],x,y,m,h[N],ks=0,ans[N];
string s;
vector<int> g[N];
map<string,int>ms;
vector<pair<int,int> >quest[N];
Point *b[N];

void dfs(int x){
        b[x]=new Point;
        for (int i=0;i<g[x].size();i++){
                int y=g[x][i];
                dfs(y);
        //link b[x],b[y]
                if ((b[x]->ts).size()<(b[y]->ts).size()){
                        Point *tmp;
                        tmp=b[x];
                        b[x]=b[y];
                        b[y]=tmp;
                }
                for (set<pair<int,int> >::iterator it=(b[y]->ts).begin();it!=(b[y]->ts).end();it++){
                        int q1=(it->first)+(b[y]->add)-(b[x]->add),q2=it->second;
                        if ((b[x]->ts).find(make_pair(q1,q2))==(b[x]->ts).end()){
                                (b[x]->ts).insert(make_pair(q1,q2));
                                (b[x]->kt)[q1]++;
                        }
                }
        }
        (b[x]->add)++;
        (b[x]->ts).insert(make_pair(-(b[x]->add),h[x]));
        (b[x]->kt)[-(b[x]->add)]=1;
        for (int i=0;i<quest[x].size();i++){
                int y=quest[x][i].first,nom=quest[x][i].second;
                ans[nom]=(b[x]->kt)[y-(b[x]->add)];
        }

}

int main(){
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
        scanf("%d\n",&n);
        ms.clear();
        for (int i=0;i<n;i++){
                cin>>s;
                if (ms[s]==0){
                        ks++;
                        ms[s]=ks;
                }
                h[i]=ms[s];
                scanf("%d\n",&pr);
                --pr;
                if (pr!=-1)g[pr].push_back(i);
                pred[i]=pr;
        }
        scanf("%d\n",&m);
        for (int i=0;i<m;i++){
                scanf("%d%d",&x,&y);
                --x;
                quest[x].push_back(make_pair(y,i));
        }
        for (int i=0;i<n;i++)
                if (pred[i]==-1)dfs(i);
        for (int i=0;i<m;i++)printf("%d\n",ans[i]);
}