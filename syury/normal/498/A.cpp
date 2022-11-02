#include<stdio.h>
#include<vector>

using namespace std;
typedef long long int lint;

struct point{
    lint x,y;
};

struct line{
    lint a,b,c;
};

point s,f;
vector<line>l;
lint n;

int sign(line t,point p){
    lint m=t.a*p.x+t.b*p.y+t.c;
    if(m>0ll){return 0;}else{return 1;}
}

int main(){
    scanf("%I64d%I64d%I64d%I64d",&s.x,&s.y,&f.x,&f.y);
    scanf("%I64d",&n);
    l.resize(n);
    int cnt=0;
    for(lint i=0;i<n;i++){
        scanf("%I64d%I64d%I64d",&l[i].a,&l[i].b,&l[i].c);
        //printf("%I64d %I64d\n",l[i].a*s.x+l[i].b*s.y+l[i].c,l[i].a*f.x+l[i].b*f.y+l[i].c);
        //printf("%d %d\n",sign(l[i],s),sign(l[i],f));
        if(sign(l[i],s)!=sign(l[i],f)){cnt++;}
    }
    printf("%d",cnt);
    return 0;
}