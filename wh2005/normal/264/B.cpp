#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N],f[329],p[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
    memset(f,0,sizeof(f));
    for(int i=2;i<=320;i++)
        if(a[1]%i==0){f[i]=1;while(a[1]%i==0) a[1]/=i;}
    p[a[1]]=1;p[1]=0;
    for(int i=2;i<=n;i++){ 
        int ans=1,y=a[i];
        for(int j=2;j<=320;j++){
            if(a[i]%j==0) ans=max(ans,f[j]+1),ans=max(ans,p[y/j]+1);
        }
        p[y]=ans;
        for(int j=2;j<=320;j++)
            if(a[i]%j==0){f[j]=max(ans,f[j]);while(a[i]%j==0) a[i]/=j;}
    }
    int ans=1;
    for(int i=1;i<=320;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}