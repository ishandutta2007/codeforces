#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int n,m;
unordered_set<int> cd;
vector<vector<int>> dc(100001);
bool ce=false;
int visited[2*100000+1];

void visit(int v, int par,int from){
    visited[v+par*n]=from;
    cd.insert(v+par*n);
    int np=1-par;
    for (auto i:dc[v]){
        if (visited[i+np*n]<0) visit(i,np,v);
        if (ce or cd.find(i)!=cd.end() or cd.find((i+n)%(2*n))!=cd.end()) ce=true;
    }
    cd.erase(v+par*n);
}

int main(){
    scanf("%d %d", &n,&m);
    set<int> cl;
    for (int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        for (int j=0;j<k;j++)
        {
            int tp;
            scanf("%d",&tp);
            dc[i].push_back(tp-1);
        }
        visited[i]=-1;
       visited[i+n]=-1;
        if (k==0) cl.insert(i);
    }
    
    int s;
    scanf("%d",&s);
    
    visit(s-1,0,s-1);
    bool iswon=false;
    vector<int> reswon=vector<int>(0);
    for (auto ncl:cl)
    {
        if (visited[n+ncl]>=0)
        {
            iswon=true;
            reswon.push_back(ncl);
            int par=1;
      //      cout<<ncl<<" "<<par<<endl;
            while (visited[par*n+ncl]!=ncl)
            {
                ncl=visited[par*n+ncl];
                par=1-par;
                reswon.push_back(ncl);
             //   cout<<ncl<<" "<<par<<" "<<visited[par*n+ncl]<<endl;
            }
            break;
        }
    }
    
    if (iswon)
    {
        printf("Win\n");
   //     cout<<reswon.size()<<endl;
        for (int i=reswon.size()-1;i>=0;i--){
            printf("%d%c",reswon[i]+1,(i>0)?' ':'\n');
        }
    }
    else{
        if (ce)
        {printf("Draw\n");}
        else {printf("Lose\n");}
    }
    return 0;
}