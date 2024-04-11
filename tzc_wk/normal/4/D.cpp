#include <bits/stdc++.h>
using namespace std;
struct obj {
    int w,h;
    int id;
}s[5002];
int head,f[5002],from[5002];
bool cmp(const obj &a,const obj &b) {
    return a.w<b.w;
}
void out(int p) {
    if(p==-1)
        return ;
    out(from[p]);
    printf("%d ",s[p].id);
}
int main() {
    int n,w,h,ans=1,p=0;
    cin>>n>>w>>h;
    for(int i,j,k=1;k<=n;++k){
        cin>>i>>j;
        if(w<i&&h<j){
            s[head].w=i;
            s[head].h=j;
            s[head++].id=k;
        }
    }
    if(head) {
        sort(s,s+head,cmp);
        for(int i=0;i<head;++i) {
            f[i]=1;
            from[i]=-1;
        }
        for(int i=1;i<head;++i){
            for(int j=0;j<i;++j){
                if(s[j].w<s[i].w&&s[j].h<s[i].h&&f[j]+1>f[i]){
                    f[i]=f[j]+1;
                    from[i]=j;
                }
            }
            if(ans<f[i]){
                ans=f[i];
                p=i;
            }
        }
        cout<<ans<<endl;
        out(p);
    }
    else	puts("0");
    return 0;
}