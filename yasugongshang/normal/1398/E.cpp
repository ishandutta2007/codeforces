#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+10;
int op[maxm],d[maxm];
int xx[maxm],num;
int ans[maxm];
int n;
struct Node{
    int a[maxm<<2];
    int sum[maxm<<2];
    void update(int x,int val,int l,int r,int node){
        if(l==r){
            a[node]+=val;
            sum[node]+=val*xx[l];
            return ;
        }
        int mid=(l+r)/2;
        if(x<=mid)update(x,val,l,mid,node*2);
        else update(x,val,mid+1,r,node*2+1);
        //
        a[node]=a[node*2]+a[node*2+1];
        sum[node]=sum[node*2]+sum[node*2+1];
    }
    int ask(int k,int l,int r,int node){//k
        if(k<=0)return 0;
        if(a[node]<=k)return sum[node];
        if(l==r)return k*xx[l];
        int mid=(l+r)/2;
        int ans=0;
        if(a[node*2+1]>=k){
            ans=ask(k,mid+1,r,node*2+1);
        }else{
            k-=a[node*2+1];
            ans=sum[node*2+1]+ask(k,l,mid,node*2);
        }
        return ans;
    }
    int askmi(int l,int r,int node){//
        if(l==r)return l;
        int mid=(l+r)/2;
        if(a[node*2])return askmi(l,mid,node*2);
        else return askmi(mid+1,r,node*2+1);
    }
}T,TT;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op[i]>>d[i];
        xx[i]=abs(d[i]);
    }
    sort(xx+1,xx+1+n);
    num=unique(xx+1,xx+1+n)-xx-1;
    for(int i=1;i<=n;i++){
        int f=(d[i]<0);
        d[i]=lower_bound(xx+1,xx+1+num,abs(d[i]))-xx;
        if(f)d[i]=-d[i];
    }
    int num1=0,num2=0;
    for(int i=1;i<=n;i++){
        if(d[i]>0){//
            if(op[i]==0){//
                T.update(d[i],1,1,num,1);
            }else{
                num2++;
                T.update(d[i],1,1,num,1);
                TT.update(d[i],1,1,num,1);
            }
        }else{//
            d[i]=-d[i];
            if(op[i]==0){
                T.update(d[i],-1,1,num,1);
            }else{
                num2--;
                T.update(d[i],-1,1,num,1);
                TT.update(d[i],-1,1,num,1);
            }
        }
        //
        ans[i]=T.sum[1];
        if(!num2)continue;
        int mi=TT.askmi(1,num,1);
        T.update(mi,-1,1,num,1);//
        ans[i]+=T.ask(num2,1,num,1);
        T.update(mi,1,1,num,1);//
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}