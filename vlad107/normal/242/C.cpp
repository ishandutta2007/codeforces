#include <map>
#include <queue>
#include <stdio.h>
#define mp make_pair
#define O puts("-1");return 0;
using namespace std;
int x,y,k,l,r,j,a,b,T,n,t;
map<pair<int,int>,int>s;
queue<pair<int,int> >q;
int hx[8]={0,1,-1,0,1,1,-1,-1},hy[8]={1,0,0,-1,-1,1,1,-1};
int main(){
    scanf("%d%d%d%d%d",&x,&y,&k,&l,&n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d",&r,&a,&b);
        for (int j=a;j<=b;j++)s[mp(r,j)]=-1;
    }
    if ((!s[mp(x,y)])||(!s[mp(k,l)])){O}
    q.push(mp(x,y));s[mp(x,y)]=0;
    while (!q.empty()){
        x=q.front().first;y=q.front().second;
        q.pop();t=s[mp(x,y)];
        for (int i=0;i<8;i++)
            if (s[mp(x+hx[i],y+hy[i])]==-1){s[mp(x+hx[i],y+hy[i])]=1+t;q.push(mp(x+hx[i],y+hy[i]));}
    }
    printf("%d\n",s[mp(k,l)]);
}