#include <bits/stdc++.h>
using namespace std;
struct voucher{
    int l;
    int r;
    int val;
} a[200005],b[200005];
int s[200005];
int cmp1(voucher &a,voucher &b){
    return a.l<b.l;
}
int cmp2(voucher &a,voucher &b){
    return a.r<b.r;
}
int n,m,ans=INT_MAX;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)	s[i]=INT_MAX;
    for(int i=0;i<n;i++){
        voucher mid;
        scanf("%d%d%d",&mid.l,&mid.r,&mid.val);
        a[i]=b[i]=mid;
    }
    sort(a,a+n,cmp1);
    sort(b,b+n,cmp2);
    int temp=0;
    for(int i=0;i<n;i++){
        while(temp<n&&b[temp].r<a[i].l){
            s[b[temp].r-b[temp].l+1]=min(s[b[temp].r-b[temp].l+1],b[temp].val);
            temp++;
        }
        if(m-(a[i].r-a[i].l+1)>0&&ans>s[m-(a[i].r-a[i].l+1)])
            ans=min(s[m-(a[i].r-a[i].l+1)]+a[i].val,ans);
    }
    if(ans==INT_MAX)	puts("-1");
    else				printf("%d\n",ans);
}