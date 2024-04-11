#include<stdio.h>

const int MN = 1500 + 1;

int N,M;
char map[MN][MN];
int V[MN][MN],dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct POINT{
    int x,y;
}Q[MN*MN],S,pos[MN][MN],next,D,v;

int main(){
    int i,j,k,h=0,t=0;
//    freopen("input","r",stdin);
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)scanf("%s",map[i]);
    for(i=0;i<N;i++)for(j=0;j<M;j++)if(map[i][j]=='S'){
        S.x=i,S.y=j;
    }
    V[S.x][S.y]=1;
    Q[t++]=S;
    while(h<t){
        for(k=0;k<4;k++){
            next.x=Q[h].x+dx[k];
            next.y=Q[h].y+dy[k];
            D.x=D.y=0;
            if(next.x<0)--D.x,next.x+=N;
            if(next.x>=N)++D.x,next.x-=N;
            if(next.y<0)--D.y,next.y+=M;
            if(next.y>=M)++D.y,next.y-=M;
            if(map[next.x][next.y]=='#')
                continue;
            v=pos[next.x][next.y];
            pos[next.x][next.y]=pos[Q[h].x][Q[h].y];
            pos[next.x][next.y].x+=D.x;
            pos[next.x][next.y].y+=D.y;
            if(V[next.x][next.y]){
                if(v.x!=pos[next.x][next.y].x || v.y!=pos[next.x][next.y].y)break;
                continue;
            }
            else{
                Q[t++]=next;
                V[next.x][next.y]=1;
            }
        }
        if(k<4)break;
        ++h;
    }
    if(h<t)puts("YES");
    else    puts("NO");
    return 0;
}