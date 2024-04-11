#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct po{
    int x,y,co;
}a[N];
struct xx{
    int x,num;
    bool operator<(const xx b)const{
        return x<b.x;
    }
};
struct yy{
    int y,num;
    bool operator<(const yy b)const{
        return y<b.y;
    }
};
vector<xx>pemx;
vector<yy>pemy;
int n,col[4];
bool chkl(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=0,cnt=0;i<(int)pemx.size();i++){
        if(a[pemx[i].num].co==u1)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==(int)pemx.size()-1||pemx[i].x!=pemx[i+1].x))break;
    }
    for(int i=0,cnt=0;i<(int)pemy.size();i++){
        if(used[pemy[i].num])continue;
        if(a[pemy[i].num].co==u2)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==(int)pemy.size()-1||pemy[i].y!=pemy[i+1].y))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool chkr(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=(int)pemx.size()-1,cnt=0;i>=0;i--){
        if(a[pemx[i].num].co==u1)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==0||pemx[i].x!=pemx[i-1].x))break;
    }
    for(int i=0,cnt=0;i<(int)pemy.size();i++){
        if(used[pemy[i].num])continue;
        if(a[pemy[i].num].co==u2)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==(int)pemy.size()-1||pemy[i].y!=pemy[i+1].y))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool chkd(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=0,cnt=0;i<(int)pemy.size();i++){
        if(a[pemy[i].num].co==u1)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==(int)pemy.size()-1||pemy[i].y!=pemy[i+1].y))break;
    }
    for(int i=0,cnt=0;i<(int)pemx.size();i++){
        if(used[pemx[i].num])continue;
        if(a[pemx[i].num].co==u2)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==(int)pemx.size()-1||pemx[i].x!=pemx[i+1].x))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool chku(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=(int)pemy.size()-1,cnt=0;i>=0;i--){
        if(a[pemy[i].num].co==u1)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==0||pemy[i].y!=pemy[i-1].y))break;
    }
    for(int i=0,cnt=0;i<(int)pemx.size();i++){
        if(used[pemx[i].num])continue;
        if(a[pemx[i].num].co==u2)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==(int)pemx.size()-1||pemx[i].x!=pemx[i+1].x))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool chklr(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=0,cnt=0;i<(int)pemx.size();i++){
        if(a[pemx[i].num].co==u1)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==(int)pemx.size()-1||pemx[i].x!=pemx[i+1].x))break;
    }
    for(int i=0,cnt=0;i<(int)pemx.size();i++){
        if(used[pemx[i].num])continue;
        if(a[pemx[i].num].co==u2)cnt++;
        used[pemx[i].num]=1;
        if(cnt>=k&&(i==(int)pemx.size()-1||pemx[i].x!=pemx[i+1].x))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool chkud(int k){
    bool used[N];
    int u1=col[1],u2=col[2],u3=col[3];
    memset(used,0,sizeof used);
    for(int i=0,cnt=0;i<(int)pemy.size();i++){
        if(a[pemy[i].num].co==u1)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==(int)pemy.size()-1||pemy[i].y!=pemy[i+1].y))break;
    }
    for(int i=0,cnt=0;i<(int)pemy.size();i++){
        if(used[pemy[i].num])continue;
        if(a[pemy[i].num].co==u2)cnt++;
        used[pemy[i].num]=1;
        if(cnt>=k&&(i==(int)pemy.size()-1||pemy[i].y!=pemy[i+1].y))break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(a[i].co==u3)cnt++;
    }
    return cnt>=k;
}
bool check(int k){
    col[1]=1,col[2]=2,col[3]=3;
    bool res=0;
    do{
        res|=chkl(k)|chkr(k)|chku(k)|chkd(k)|chklr(k)|chkud(k);
    }while(next_permutation(col+1,col+4));
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].co);
        pemx.push_back((xx){a[i].x,i});
        pemy.push_back((yy){a[i].y,i});
    }
    sort(pemx.begin(),pemx.end());
    sort(pemy.begin(),pemy.end());
    int l=1,r=n/3,mid,ans=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    printf("%d",ans*3);
    return  0;
}