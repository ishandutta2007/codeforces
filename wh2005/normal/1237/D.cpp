#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,a[N],s[N],top,lst[N],ans[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[n+i]=a[n+n+i]=a[n+n+n+i]=a[n+n+n+n+i]=a[i];
    }
    ans[n*5+1]=-1,a[n*5+1]=1e9+7;
    top=1;s[top]=n*5+1;
    for(int i=n*5;i>=1;i--){
        while(a[i]>a[s[top]]) top--;
        lst[i]=s[top];
        s[++top]=i;
    }
    memset(s,0,sizeof(s));top=0;
    for(int i=n*5;i>=1;i--){
        if(!top) ans[i]=ans[lst[i]];
        else{
            int l=1,r=top;ans[i]=-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(a[s[mid]]<(a[i]+1)/2) l=mid+1,ans[i]=s[mid];
                else r=mid-1;
            }
            if(ans[i]==-1||lst[i]<=ans[i]) ans[i]=ans[lst[i]];
        }
        while(top&&a[i]<a[s[top]]) top--;
        s[++top]=i;
    }
    for(int i=1;i<=n;i++)
        if(ans[i]==-1) printf("-1 ");
        else printf("%d ",ans[i]-i);
    puts("");
    return 0;
}
/*
 (x+1)/2


11 5 2 7 11 5 2 7 11 5 2 7 11 5 2 7

*/