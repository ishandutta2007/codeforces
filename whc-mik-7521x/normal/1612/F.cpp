#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,q;
map<pair<int,int>,bool>mp;
struct node{
    int x,y,t;
    bool operator<(const node k)const{
        if(t==k.t){
            if(x==k.x)return y<k.y;
            return x<k.x;
        }
        return t>k.t;
    }
};
int solve(){
    priority_queue<node>q;
    q.push(node{1,1,0});
    int last=-1,lastx=0,lasty=0;
    while(q.size()){
        node k=q.top();
        if(k.x==n&&k.y==m)return k.t;
        q.pop();
        if(k.t==last){
            if(k.x==lastx)continue;
            if(k.y<=lasty)continue;
        }
        else last=k.t,lastx=0,lasty=0;
        lastx=k.x;
        lasty=max(k.y,lasty);
        q.push(node{k.x,min(k.x+k.y+mp[make_pair(k.x,k.y)],m),k.t+1});
        q.push(node{min(k.x+k.y+mp[make_pair(k.x,k.y)],n),k.y,k.t+1});
    }
    return -1;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mp[make_pair(x,y)]=1;
    }
    printf("%d",solve());
    return  0;
}