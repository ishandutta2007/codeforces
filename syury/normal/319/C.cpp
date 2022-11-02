#include<cstdio>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;
typedef long long int lint;
typedef long double ldb;
const ldb eps=1e-9;

struct line{
    lint k,b;
    line(lint _k,lint _b):k(_k),b(_b){}
    line(){}
};

vector<lint>a,b,ans;
lint n;
vector<line>lines;
vector<lint>convex;

ldb intersection(line l1,line l2){
    return (l2.b-l1.b)*1.0/(l1.k-l2.k);
}

void add(line l){
    lint pos=lines.size();
    lines.push_back(l);
    while(convex.size()>1){
        int last=convex[convex.size()-1];
        int plast=convex[convex.size()-2];
        ldb x1=intersection(lines[last],lines[plast]);
        ldb x2=intersection(lines[last],l);
        if(x1-x2<-eps){break;}
        else{convex.erase(--convex.end());}
    }
    convex.push_back(pos);
}

/*line find(lint x){
    int l=0,r=convex.size()-1;
    while(r-l>1){
       int m=(l+r)/2;
       ldb xm=intersection(lines[convex[m]],lines[convex[m+1]]);
       if(x-xm>-eps){r=m;}
       else{l=m;}
    }
    if(l==r){return lines[convex[l]];}
    else{
        ldb x1=intersection(lines[convex[l]],lines[convex[r]]);
        if(x-x1<-eps){return lines[convex[l]];}else{return lines[convex[r]];}
    }
}*/

int main(){
    scanf("%lld",&n);
    a.resize(n);
    b.resize(n);
    ans.resize(n);
    for(int i=0;i<n;i++){scanf("%lld",&a[i]);}
    for(int i=0;i<n;i++){scanf("%lld",&b[i]);}
    ans[0]=0;
    line first(b[0],0);
    add(first);
    lint ptr=0;
    for(lint i=1;i<n;i++){
        line j;
        while(ptr<convex.size()-1 && intersection(lines[convex[ptr]],lines[convex[ptr+1]])-a[i]<eps){ptr++;}
        if(ptr>0 && (intersection(lines[convex[ptr]],lines[convex[ptr-1]])-a[i]>eps)){ptr--;}
        j=lines[convex[ptr]];
        ans[i]=j.k*a[i]+j.b;
        line curr(b[i],ans[i]);
        add(curr);
    }
    printf("%lld",ans[n-1]);
    return 0;
}