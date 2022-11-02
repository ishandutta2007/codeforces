#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+9;
int T,n,m,x[N],y[N],sa[N],rk[N],c[N],ht[N];
char s[N];
void get_SA(){
    for(int i=1;i<=m;i++) c[i]=0;
    for(int i=1;i<=n;i++) ++c[x[i]=s[i]];
    for(int i=2;i<=m;i++) c[i]+=c[i-1];
    for(int i=n;i>=1;i--) sa[c[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1){
        int num=0;
        for(int i=n-k+1;i<=n;i++) y[++num]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) y[++num]=sa[i]-k;
        for(int i=1;i<=m;i++) c[i]=0;
        for(int i=1;i<=n;i++) c[x[i]]++;
        for(int i=2;i<=m;i++) c[i]+=c[i-1];
        for(int i=n;i>=1;i--) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1,num=1;
        for(int i=2;i<=n;i++)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:(++num); 
        if(num==n) break;
        m=num;
    }
    for(int i=1;i<=n;i++) rk[sa[i]]=i;
    return ;
}
void get_HT(){
    int k=0;
    for(int i=1;i<=n;i++){
        if(rk[i]==1) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(j+k<=n&&i+k<=n&&s[j+k]==s[i+k]) k++;
        ht[rk[i]]=k;
    }
}
struct Stac{int h,w;}st[N];
int top;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);n=strlen(s);for(int i=n;i>=1;i--) s[i]=s[i-1];
        m=122;get_SA();get_HT();top=0;ll ans=0;
        for(int i=1;i<=n;i++){
            int xt=max(ht[i],ht[i+1]);
            ans+=(n-sa[i]+1-xt);
        }
        for(int i=2;i<=n;i++){
            Stac xt;xt.h=ht[i],xt.w=1;
            if(!top||xt.h>st[top].h) st[++top]=xt;
            else{
                while(top&&xt.h<=st[top-1].h){
                    ans+=1ll*(st[top].h-st[top-1].h)*(st[top].w+1)*(st[top].w+1);
                    st[top-1].w+=st[top].w;top--;
                }
                if(top&&st[top].h>=xt.h&&st[top-1].h<xt.h){
                    ans+=1ll*(st[top].h-xt.h)*(st[top].w+1)*(st[top].w+1);
                    xt.w+=st[top].w;top--;
                }
                st[++top]=xt;
            }
        }
        while(top){
            ans+=1ll*(st[top].h-st[top-1].h)*(st[top].w+1)*(st[top].w+1);
            st[top-1].w+=st[top].w;top--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}