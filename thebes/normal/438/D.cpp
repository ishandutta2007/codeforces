#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 1e5+5;
int st[3*MN], sm[3*MN], arr[MN], n, m, i, x, y, k;
void build(int i,int s,int e){
    if(s != e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        st[i]=arr[st[2*i]]>arr[st[2*i+1]]?st[2*i]:st[2*i+1];
        sm[i] = sm[2*i]+sm[2*i+1];
    }
    else st[i] = s, sm[i] = arr[s];
}
void upd(int i,int s,int e,int ind){
    if(s != e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
        else upd(2*i,s,(s+e)/2,ind);
        st[i]=arr[st[2*i]]>arr[st[2*i+1]]?st[2*i]:st[2*i+1];
        sm[i] = sm[2*i]+sm[2*i+1];
    }
    else st[i] = s, sm[i] = arr[s];
}
int mx(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return mx(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return mx(2*i,s,(s+e)/2,ss,se);
    else{
        int a=mx(2*i,s,(s+e)/2,ss,se),b=mx(2*i+1,(s+e)/2+1,e,ss,se);
        return arr[a]>arr[b]? a:b;
    }
}
int rs(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return sm[i];
    else if((s+e)/2<ss) return rs(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return rs(2*i,s,(s+e)/2,ss,se);
    else return rs(2*i,s,(s+e)/2,ss,se)+rs(2*i+1,(s+e)/2+1,e,ss,se);
}
signed main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);
    for(;m;m--){
        scanf("%d%d%d",&i,&x,&y);
        if(i==1) printf("%lld\n",rs(1,1,n,x,y));
        else if(i==2){
            scanf("%lld",&k);
            int p = mx(1,1,n,x,y);
            while(arr[p] >= k){
                arr[p] %= k; upd(1,1,n,p);
                p = mx(1,1,n,x,y);
            }
        }
        else if(i==3){
            arr[x] = y;
            upd(1,1,n,x);
        }
    }
    return 0;
}