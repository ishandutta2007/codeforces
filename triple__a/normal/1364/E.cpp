#include<bits/stdc++.h>
using namespace std;

mt19937 rng(time(NULL));

const int maxn=4007;
int n;
int aa[maxn],u,v;
int bb[maxn][maxn];
stack<int> q;

int query(int u,int v){
    cout<<"? "<<u<<" "<<v<<endl;
    int w;
    cin>>w;
    return w;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) q.push(i);
    while (q.size()>2){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        int c=q.top();
        q.pop();
        if (!bb[a][b]) bb[b][a]=bb[a][b]=query(a,b);
        if (!bb[a][c]) bb[c][a]=bb[a][c]=query(a,c);
        if (bb[a][b]==bb[a][c]) {q.push(c), q.push(b); continue;}
        if ((bb[a][b]|bb[a][c])==bb[a][b]) q.push(c),q.push(a);
        else q.push(b), q.push(a);
    }
    int res=u;
    u=q.top(); q.pop(),v=q.top();
    for (int i=1;i<=50;++i){
        int w=u;
        while (w==u||w==v){
            w=rng()%n+1;
        }
        int au=query(u,w), av=query(v,w);
        if (au==av) continue;
        if (au<av){
            res=u; break;
        }
        else{
            res=v; break;
        }
    }
    for (int i=1;i<=n;++i){
        if (i==res) continue;
        aa[i]=query(i,res);
    }
    cout<<"! ";
    for (int i=1;i<=n;++i) cout<<aa[i]<<" ";
    cout<<endl;
}