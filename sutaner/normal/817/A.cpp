#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
/*struct edge{
    int next,to;
    edge(int next,int to):next(next),to(to){}
    edge(){}
}e[maxn<<1];
int cnt=1,h[maxn];
void Add_Edge(int fr,int to){
    e[++cnt]=edge(h[fr],to);
    h[fr]=cnt;
    e[++cnt]=edge(h[to],fr);
    h[to]=cnt;
}*/
int main(){
    /*freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);*/
    int x0,y0,x1,y1;
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    int a=(x1-x0);
    int b=(y1-y0);
    int x,y;
    scanf("%d%d",&x,&y);
    if(a%x!=0||b%y!=0)printf("NO");
    else{
        a/=x,b/=y;
        if((a+b)%2!=0)printf("NO");
        else printf("YES");
    }
    return 0;
}