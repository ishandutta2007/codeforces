#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
#define X first
#define Y second

const int inf=1e9+10;
const int N=1e6+10;


int n,v[N][2];
int ival[N],rval[N][2];
string s[N];
int w[N];
void prepare(){
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>s[i];
                if (s[i]=="IN"){
                        cin>>w[i];
                        continue;
                }
                if (s[i]=="NOT"){
                        cin>>v[i][0];
                        continue;
                }
                cin>>v[i][0]>>v[i][1];
        }
}
int cal(int x,int y,string& ops){
        if (ops=="AND")
                return x&y;
        if (ops=="OR") return x|y;
        if (ops=="XOR") return x^y;
        exit(-1);
        return 0;
}
void DFS(int root){
        if (s[root]=="IN"){
                ival[root]=w[root];
                return;
        }
        if (s[root]=="NOT"){
                DFS(v[root][0]);
                ival[root]=!ival[v[root][0]];
                return;
        }
        DFS(v[root][0]);
        DFS(v[root][1]);
        ival[root]=cal(ival[v[root][0]],ival[v[root][1]],s[root]);
        //cout<<root<<" "<<ival[root]<<'\n';
}
void DFS2(int root){
        if (s[root]=="IN") return;
        if (s[root]=="NOT"){
                for(int i=0;i<=1;i++)
                        rval[v[root][0]][i]=rval[root][i^1];
                DFS2(v[root][0]);
                return;
        }
        for(int i=0;i<=1;i++){
                int cur=v[root][i],oth=v[root][i^1];
                for(int j=0;j<=1;j++)
                        rval[cur][j]=rval[root][cal(j,ival[oth],s[root])];
        }
        DFS2(v[root][0]);
        DFS2(v[root][1]);
}
int main(){
        prepare();
        DFS(1);
        rval[1][0]=0;
        rval[1][1]=1;
        DFS2(1);
        for(int i=1;i<=n;i++) if (s[i]=="IN") cout<<rval[i][w[i]^1];
}