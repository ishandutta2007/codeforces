#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<int>a,b,c,t;
vector<pair<int,int> >na;
int n;

int sum(int v,int l,int r,int ul,int ur){
    if(l==ul && r==ur){return t[v];}
    if(ul>ur){return 0;}
    int m=(r+l)>>1;
    return sum(2*v,l,m,ul,min(m,ur))+sum(2*v+1,m+1,r,max(m+1,ul),ur);
}

void upd(int v,int l,int r,int pos,int val){
    if(l==r){t[v]=val;return;}
    int m=(r+l)>>1;
    if(pos<=m){
        upd(2*v,l,m,pos,val);
    }
    else{
        upd(2*v+1,m+1,r,pos,val);
    }
    t[v]=t[2*v]+t[2*v+1];
}

int main(){
    scanf("%d",&n);
    a.resize(n);na.resize(n);
    int maxa=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        na[i].first=a[i];
        na[i].second=i;
    }
    int prev=0;
    int curr=0;
    sort(na.begin(),na.end());
    for(int i=0;i<n;i++){
        int cur=na[i].first;
        if(na[i].first==prev){na[i].first=curr;}
        else{na[i].first=++curr;}
        a[na[i].second]=na[i].first;
        prev=cur;
        maxa=max(na[i].first,maxa);
    }
    vector<pair<int,int> >().swap(na);
    b.resize(maxa+1);c.resize(maxa+1);
    t.resize(4*(n+1));
    for(int i=0;i<n-1;i++){c[a[i]]++;}
    long long int ans=0;
    for(int i=n-1;i>0;i--){
        b[a[i]]++;
        int j=i-1;
        int nv=sum(1,0,n,b[a[i]],b[a[i]])+1;
        upd(1,0,n,b[a[i]],nv);
        ans+=sum(1,0,n,0,c[a[j]]-1);
        c[a[j]]--;
    }
    printf("%lld\n",ans);
    return 0;
}