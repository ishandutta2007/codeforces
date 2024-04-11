#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e6+9;
int n,a[N],top,mx;ll num;
struct Stac{int w,h;}st[N];

int main(){
    scanf("%d",&n);mx=0,num=0;int num2=0,mx2=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n+1;i<=(n<<1);i++) a[i]=a[i-n];
    for(int i=1;i<=n;i++){
        if(a[i]>mx) mx=a[i],num=1;
        else if(a[i]==mx) num++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]<mx&&a[i]>mx2) mx2=a[i],num2=1;
        else if(a[i]==mx2) num2++;
    }
    top=0;ll ans=0,pat=0;
    for(int i=(n<<1);i>=1;i--){
        Stac x;x.w=1,x.h=a[i];int area=0;
        if(!top||st[top].h>x.h) area=(!(a[i]==mx&&st[top].h==mx)),st[++top]=x;
        else{
            while(top&&st[top].h<=x.h){
                if(st[top].h==x.h) x.w+=st[top].w;
                if(st[top].h!=mx) area+=st[top].w;
                top--;
            }
            if(top) area+=1;
            st[++top]=x;
        }
        if(i<=n&&a[i]!=mx) ans+=area;
        if(i<=n&&a[i]==mx) pat+=area;
    }
    top=0;
    for(int i=1;i<=(n<<1);i++){
        Stac x;x.w=1,x.h=a[i];int area=0;
        if(!top||st[top].h>x.h) area=(!(a[i]==mx&&st[top].h==mx)),st[++top]=x;
        else{
            while(top&&st[top].h<=x.h){
                if(st[top].h==x.h) x.w+=st[top].w;
                if(st[top].h!=mx) area+=st[top].w;
                top--;
            }
            if(top) area+=1;
            st[++top]=x;
        }
        if(i>n&&a[i-n]!=mx) ans+=area;
        if(i>n&&a[i]==mx) pat+=area;
    }
    if(num==1) ans-=2ll*num2;
    ans=(ans+pat)/2;
    printf("%lld\n",ans+1ll*num*(num-1)/2);
    return 0;
}