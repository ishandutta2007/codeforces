#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
struct arr {
    int x,y;
    arr (int _x=0,int _y=0):x(_x),y(_y) {}
} b[100000],a;
int x,y,n,m,t;
long long calc(arr x,arr y) {
    return(static_cast<long long>(x.x)*y.y-static_cast<long long>(x.y)*y.x);
}
arr cal(arr x,arr y) {
    return(arr(x.x-y.x,x.y-y.y));
}
int get(int l,int r) {
    if (l+1>=r) return(l);
    int mid=(l+r)/2;
    if (calc(cal(b[mid],b[0]),cal(a,b[0]))<=0) return(get(mid,r));
      else return(get(l,mid));
}
int FALSE() {
    printf("NO");
    exit(0);
}
int main() {
    //freopen("113.B.in","r",stdin);freopen("113.B.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;++i) 
        scanf("%d%d",&b[i].x,&b[i].y);
    scanf("%d",&m);
    for (int i=0;i!=m;++i) { 
        scanf("%d%d",&a.x,&a.y);
        t=get(1,n);
        if (t==n-1||(t==1&&calc(cal(b[1],b[0]),cal(a,b[0]))>=0)) FALSE(); 
        if (calc(cal(b[t+1],b[t]),cal(a,b[t]))>=0) FALSE();               
    }
    printf("YES");
}