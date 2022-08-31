#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int a,b;
}x[6000];
int compare(atom k1,atom k2){
    return k1.a<k2.a||(k1.a==k2.a&&k1.b<k2.b);
}
int main(){
    int n; scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d%d",&x[i].a,&x[i].b);
    sort(x+1,x+n+1,compare); int pre=x[1].b;
    for (int i=2;i<=n;i++)
        if (x[i].b<pre) pre=x[i].a; else pre=x[i].b;
    cout<<pre<<endl; return 0;
}