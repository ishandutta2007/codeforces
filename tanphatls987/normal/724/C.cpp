#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf=1e16;
const int N=1e5+10;
const int dx[4]={1,1,-1,-1};
const int dy[4]={1,-1,-1,1};

int n,m;
ll d[4][N][4];
struct info{
    int x,y,dir;
    info (int _x=0,int _y=0,int _dir=0){
        x=_x;y=_y;dir=_dir;
    }
};

ll *pd(info cur){
    if (cur.x==0) return &d[0][cur.y][cur.dir];
    if (cur.x==n) return &d[1][cur.y][cur.dir];
    if (cur.y==0) return &d[2][cur.x][cur.dir];
    if (cur.y==m) return &d[3][cur.x][cur.dir];
}
int calmove(info cur){
    if (cur.dir==0) return min(n-cur.x,m-cur.y);
    if (cur.dir==1) return min(n-cur.x,cur.y);
    if (cur.dir==2) return min(cur.x,cur.y);
    if (cur.dir==3) return min(cur.x,m-cur.y);
}
void chadir(info &cur){
    if (cur.dir==0){ cur.dir=(cur.x==n?3:1);
    }else if (cur.dir==1){ cur.dir=(cur.x==n?2:0);
    }else if (cur.dir==2){ cur.dir=(cur.x==0?1:3);
    }else if (cur.dir==3){ cur.dir=(cur.x==0?0:2);}
}
void trans(info &cur){
    int go=calmove(cur);
    cur.x+=dx[cur.dir]*go;
    cur.y+=dy[cur.dir]*go;
}
ll solve(int x,int y){
    ll ans=inf;
    for(int i=0;i<4;i++){
        info cur=info(x,y,i);
        trans(cur);
//        cout<<x<<" "<<y<<" "<<cur.x<<" "<<cur.y<<'\n';
        cur.dir=i^2;
        ll val=*pd(cur);
        if (val) ans=min(ans,val+abs(cur.x-x)-1);
    }
    if (ans==inf) return -1;
    return ans;
}
void prepare(){
    int test;
    scanf("%d%d%d",&n,&m,&test);
    info cur=info(0,0,0);
    *(pd(cur))=1;
    while (1){
        ll cdist=*pd(cur);
        int go=calmove(cur);
        trans(cur);
        if ((cur.x==0||cur.x==n)&&(cur.y==0||cur.y==m)) break;
        chadir(cur);
        if (*pd(cur)) break;
        *(pd(cur))=cdist+go;
    }
    while (test--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",solve(x,y));
    }
}

int main(){
    prepare();

}