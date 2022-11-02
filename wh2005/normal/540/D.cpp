#include<bits/stdc++.h>
using namespace std;
#define db double
int r,s,p;
db f[109][109][109][3];
db R(int x,int y){return (x*1.0)/(y*1.0);}
db dfs(int x,int y,int z,int flag){
    if(flag==0&&!x) return 0;
    if(flag==1&&!y) return 0;
    if(flag==2&&!z) return 0;
    if(x&&!y&&!z){if(flag==0) return 1;return 0;}
    if(!x&&y&&!z){if(flag==1) return 1;return 0;}
    if(!x&&!y&&z){if(flag==2) return 1;return 0;}
    if(!x&&!y&&!z) return 0;
    if(f[x][y][z][flag]>=0) return f[x][y][z][flag];
    int sum=x*y+y*z+x*z;db ans=0;
    if(x&&y) ans+=R(x*y,sum)*dfs(x,y-1,z,flag);
    if(y&&z) ans+=R(y*z,sum)*dfs(x,y,z-1,flag);
    if(x&&z) ans+=R(x*z,sum)*dfs(x-1,y,z,flag);
    return f[x][y][z][flag]=ans;
}

int main(){
    memset(f,-1,sizeof(f));
    scanf("%d%d%d",&r,&s,&p);
    for(int i=0;i<3;i++){
        printf("%.12lf ",dfs(r,s,p,i));
    }
    return 0;
}