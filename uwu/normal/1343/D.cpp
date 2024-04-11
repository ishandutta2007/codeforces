#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200001;
int n,k; 
int lazy[MAXN*8];

void seg_update(int node,int start,int end,int l,int r,int val){
    if (l>end||r<start) return;
    if (start>=l&&end<=r){
        lazy[node]+=val;
        return;
    }
    int mid=(start+end)/2;
    seg_update(node*2,start,mid,l,r,val);
    seg_update(node*2+1,mid+1,end,l,r,val);
}

int query(int node,int start,int end,int index){
    if (start==end){
        int temp=lazy[node];
        lazy[node]=0;
        return temp;
    }
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
    int mid=(start+end)/2;
    if (index<=mid) return query(node*2,start,mid,index);
    else return query(node*2+1,mid+1,end,index);

}

void update(int a,int b){
    seg_update(1,1,2*k,2,2*k,2);
    seg_update(1,1,2*k,min(a,b)+1,max(a,b)+k,-1);
    seg_update(1,1,2*k,a+b,a+b,-1);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        vector<int> arr(n+1);
        for (int i=1;i<=n;++i){ cin>>arr[i]; }
        for (int i=1;i<=n/2;++i){ update(arr[i],arr[n-i+1]); }
        int ans=0x3f3f3f3f;
        for (int i=2;i<=2*k;++i){
            //cout << i << "->" <<query(1,1,2*k,i) << " ";
            ans=min(ans,query(1,1,2*k,i));
        }
        cout << ans << '\n';
    }
}