#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;


int n,n1,com[N];

int e[N][2];
int w[N];
queue <int> q1;
vector <int> v[N];
void BFS1(int st){
    q1.push(st);
    com[st]=++n1;
    while (!q1.empty()){
        int x=q1.front();q1.pop();
        for(auto y:v[x]) if (!com[y]&&w[y]==w[x]){
            com[y]=n1;
            q1.push(y);
        }
    }
}

int q[N];
int pa[N],lv[N];
int BFS(int st){
    int top=1,bot=1;
    pa[st]=0;
    q[1]=st;
    lv[st]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=pa[x]){
            pa[y]=x;
            lv[y]=lv[x]+1;
            q[++bot]=y;
        }
    }
    return q[n1];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",w+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        e[i][0]=x;e[i][1]=y;
    }
    for(int i=1;i<=n;i++) if (!com[i]) BFS1(i);
//    cout<<n1<<'\n';
    for(int i=1;i<=n1;i++) v[i].clear();
    for(int i=1;i<n;i++)
        if (com[e[i][0]]!=com[e[i][1]]){
            int x=com[e[i][0]],y=com[e[i][1]];
            v[x].push_back(y);
            v[y].push_back(x);
//            cout<<x<<" "<<y<<'\n';
        }
    int en=BFS(BFS(1));
    cout<<lv[en]/2;
}