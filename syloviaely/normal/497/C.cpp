#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct atom{
    int where,k1,f,w;
}A[500000];
struct point{
    int where,w;
};
int operator < (point k1,point k2){
    return (k1.w<k2.w)||(k1.w==k2.w&&k1.where<k2.where);
}
set<point>S;
int n,m,num[200000],r[200000],ans[200000];
int compare(atom k1,atom k2){
    return k1.w<k2.w||(k1.w==k2.w&&k1.k1<k2.k1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); 
        A[i]=(atom){i,1,k2,k1};
    }
    scanf("%d",&m); int len=n;
    for (int i=1;i<=m;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
        len++; A[len]=(atom){i,0,0,k1};
        len++; A[len]=(atom){i,0,1,k2+1}; num[i]=k3; r[i]=k2;
    }
    sort(A+1,A+len+1,compare);
//  for (int i=1;i<=len;i++) cout<<A[i].where<<" "<<A[i].k1<<" "<<A[i].f<<" "<<A[i].w<<endl;
    for (int i=1;i<=len;i++)
        if (A[i].k1==0){
            if (A[i].f==0){
                S.insert((point){A[i].where,r[A[i].where]});
            } else if (A[i].f==1){
                if (num[A[i].where]) S.erase((point){A[i].where,A[i].w});
            }
        } else {
            set<point>::iterator k1=S.lower_bound((point){0,A[i].f});
            if (k1==S.end()){cout<<"NO"<<endl; return 0;}
            int k2=(*k1).where; num[k2]--; ans[A[i].where]=k2;
            if (num[k2]==0) S.erase((point){k2,r[k2]});
        }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<endl;
    return 0;
}