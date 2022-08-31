#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct atom{
    int a,b;
    void scan(){
        scanf("%d%d",&a,&b);
    }
}x[2000];
int n,A[2000],rem;
int main(){
    scanf("%d",&n); long long num=1e18;
    for (int i=1;i<=n;i++) x[i].scan();
    for (int now=1;now<=1000;now++){
        rem=(n/2); int flag=0,len=0; long long ans=0;
        for (int i=1;i<=n;i++)
            if (x[i].a>now&&x[i].b>now) flag=1;
            else if (x[i].a>now) ans+=x[i].a;
            else if (x[i].b>now){
                rem--; ans+=x[i].b;
            } else {
                ans+=x[i].a; len++; A[len]=x[i].b-x[i].a;
            }
        if (flag||rem<0) continue;
        sort(A+1,A+len+1);
        for (int i=1;i<=min(len,rem);i++) ans+=min(0,A[i]);
        num=min(num,ans*now);
    }
    cout<<num<<endl;
}