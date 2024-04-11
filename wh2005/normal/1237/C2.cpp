#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n;
struct pp{int x,y,z,id;}a[N];

bool cmp(pp u,pp v){
    return u.x==v.x?(u.y==v.y?(u.z<v.z):(u.y<v.y)):(u.x<v.x);
}

int l[N],r[N];

void del(int x){
    l[r[x]]=l[x],r[l[x]]=r[x];
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
    r[0]=1;
    for(int i=r[0];i!=n+1;i=r[i]){
        if(r[i]!=n+1){
            if(a[i].x==a[r[i]].x&&a[i].y==a[r[i]].y){
                printf("%d %d\n",a[i].id,a[r[i]].id);
                del(r[i]);del(i);
            }
        }
    }
    for(int i=r[0];i!=n+1;i=r[i]){
        if(r[i]!=n+1){
            if(a[i].x==a[r[i]].x){
                printf("%d %d\n",a[i].id,a[r[i]].id);
                del(r[i]);del(i);
            }
        }
    }
    for(int i=r[0];i!=n+1;i=r[i]){
        if(r[i]!=n+1){
            printf("%d %d\n",a[i].id,a[r[i]].id);
            del(r[i]);del(i);
        }
    }
    return 0;
}