#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,fa[N],tim[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;tim[x]=min(tim[x],tim[y]);}
struct pos1{
    int x,y,num;
    bool operator<(const pos1 b)const{
        return x==b.x?y<b.y:x<b.x;
    }
};
struct pos2{
    int x,y,num;
    bool operator<(const pos2 b)const{
        return y==b.y?x<b.x:y<b.y;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vector<pos1>xx;
        vector<pos2>yy;
        for(int i=1;i<=n;i++){
            fa[i]=i;
            int x,y;
            scanf("%d%d%d",&x,&y,&tim[i]);
            xx.push_back((pos1){x,y,i});
            yy.push_back((pos2){x,y,i});
        }
        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());
        for(int i=0;i<n-1;i++){
            if(xx[i].x==xx[i+1].x&&xx[i+1].y-xx[i].y<=k){
                int fx=find(xx[i].num),fy=find(xx[i+1].num);
                if(fx!=fy)unnion(fx,fy);
            }
        }
        for(int i=0;i<n-1;i++){
            if(yy[i].y==yy[i+1].y&&yy[i+1].x-yy[i].x<=k){
                int fx=find(yy[i].num),fy=find(yy[i+1].num);
                if(fx!=fy)unnion(fx,fy);
            }
        }
        priority_queue<int>q;
        for(int i=1;i<=n;i++){
            if(fa[i]==i)q.push(tim[i]);
        }
        int now=0;
        while(q.size()){
            q.pop();
            if(!q.size()||q.top()<=now)break;
            now++;
        }
        printf("%d\n",now);
    }
    return  0;
}