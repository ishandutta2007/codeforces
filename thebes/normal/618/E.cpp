#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;

const long double PI = 3.14159265358979;
const int MN = 3e5+5;
struct nd{long double a, b; int c;}st[5*MN];
int n, m, i, x, y, z;


void build(int i,int s,int e){
    if(s!=e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        st[i].b=st[2*i].b+st[2*i+1].b;
    }
    else st[i].b = 1;
}

void upd(int i,int s,int e,int idx,int t,int val){
    if(s!=e){
        if((s+e)/2<idx) upd(2*i+1,(s+e)/2+1,e,idx,t,val);
        else upd(2*i,s,(s+e)/2,idx,t,val);
        st[i].c = (st[2*i].c+st[2*i+1].c)%360;
        long double aa = st[2*i+1].a+st[2*i].c;
        if(aa>=360) aa -= 360;
        long double dx = st[2*i].b*cos(st[2*i].a/180*PI)+st[2*i+1].b*cos(aa/180*PI);
        long double dy = st[2*i].b*sin(st[2*i].a/180*PI)+st[2*i+1].b*sin(aa/180*PI);
        st[i].b = sqrt(dx*dx+dy*dy);
        st[i].a = atan2(dy,dx)/PI*180;
    }
    else{
        if(t==1) st[i].b += val;
        else{
            st[i].a -= val;
            st[i].c -= val;
            if(st[i].a<0) st[i].a += 360;
            if(st[i].c<0) st[i].c += 360;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        upd(1,1,n,y,x,z);
        long double dx = st[1].b*cos(st[1].a/180*PI);
        long double dy = st[1].b*sin(st[1].a/180*PI);
        cout << fixed << setprecision(9) << dx << " " << dy << "\n";
    }
    return 0;
}