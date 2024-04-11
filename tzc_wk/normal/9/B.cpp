#include <bits/stdc++.h>
#define re register
#define in long long
using namespace std;
inline in read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=(X<<3)+(X<<1)+c-'0',c=getchar();
    return X*w;
}
inline double dis(double xa,double ya,double xb,double yb) {
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
const double EPS=1e-6;
in n,vb,vs;
in x[110];
in xs,ys;
int main() {
    n=read(),vb=read(),vs=read();
    for (re int i=1;i<=n;i++) x[i]=read();
    xs=read(),ys=read();
    double Min=2e9; int ans=0;
    for (re int i=2;i<=n;i++) {
        double d=(double)x[i]/(double)vb+dis(x[i],0,xs,ys)/(double)vs;
        if (fabs(d-Min)<EPS) {
            if (dis(x[i],0,xs,ys)<dis(x[ans],0,xs,ys)) ans=i;
        }
        else if (d<Min) Min=d,ans=i;
    }
    cout<<ans<<endl;
    return 0;
}