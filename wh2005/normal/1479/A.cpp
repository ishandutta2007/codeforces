#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N],cnt;
int query(int x){
    if(a[x]) return a[x];
    printf("? %d\n",x);fflush(stdout);
    scanf("%d",&a[x]);cnt--;return a[x];
}
void Query(int x){int t=query(x);return ;}

int main(){
    scanf("%d",&n);cnt=100;
    if(n>1){
        Query(1);Query(2);Query(n-1);Query(n);
        if(a[1]<a[2]){printf("! 1\n");return 0;}
        if(a[n-1]>a[n]){printf("! %d\n",n);return 0;}
    }
    a[0]=n+1,a[n+1]=n+1;
    int l=1,r=n;
    while(r-l>10){
        int mid=(l+r)>>1;
        Query(mid);Query(mid+1);
        if(a[mid]<a[mid+1]) r=mid;
        else l=mid;
    }
    for(int i=l;i<=r;i++) Query(i);
    for(int i=1;i<=n;i++)
        if(a[i]&&a[i-1]&&a[i+1]){
            if(a[i]<a[i+1]&&a[i]<a[i-1]){
                printf("! %d\n",i);
                return 0;
            }
        }
    return 0;
}