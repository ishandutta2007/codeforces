#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second


const int N=3e5+10;


int n,m,root;

int v[N][2],dir[N];
vector <int> e[N];


void prepare(){
    cin>>n>>m>>root;
    for(int i=1;i<=m;i++)
        cin>>dir[i]>>v[i][0]>>v[i][1];
}
int ans[N];
int h[N];
int q[N];
void BFS(int st,int key){
    int top=1,bot=1;
    q[1]=st;
    memset(h,0,sizeof(h));
    memset(ans,-1,sizeof(ans));
    h[st]=1;

    while (top<=bot){
        int x=q[top++];
        for(auto i:e[x]) if (ans[i]==-1){
            int cdir=(v[i][0]!=x);
            int y=v[i][cdir^1];
//            cout<<x<<"->"<<y<<'\n';
            if (!h[y]) {
                if (key==0||dir[i]==1){
                    q[++bot]=y;
                    h[y]=1;
                }
            }
            ans[i]=cdir^key;
        }
    }
}
void solve(){
    for(int i=1;i<=m;i++){
        e[v[i][0]].push_back(i);
        if (dir[i]==2)
            e[v[i][1]].push_back(i);
    }
    for(int j=0;j<=1;j++){
        BFS(root,j);
        cout<<count(h+1,h+n+1,1)<<'\n';
        for(int i=1;i<=m;i++) if (dir[i]==2){
            int cans=ans[i];
            if (cans==-1) cans=0;
            cout<<(cans?'-':'+');
        }
        cout<<'\n';
    }
}
int main(){
    prepare();
    solve();
}