#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 1e6+6;
ll n, w, i, j, k, d, x, ans[MN], arr[MN], lz[3*MN], seg[3*MN];
deque<pair<ll,ll>> st;

inline void upd_lz(int i,int s,int e){
    seg[i]+=1LL*lz[i]*(e-s+1);
    if(s!=e){
        lz[2*i] += lz[i];
        lz[2*i+1] += lz[i];
    }
    lz[i] = 0;
}

void upd(int i,int s,int e,int ss,int se,int val){
    if(lz[i]) upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i] = val;
        upd_lz(i,s,e);
    }
    else if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val);
    else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val);
    else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
}

void go(int i,int s,int e){
    upd_lz(i,s,e);
    if(s==e) ans[s]+=seg[i];
    else go(2*i,s,(s+e)/2), go(2*i+1,(s+e)/2+1,e);
}

int main(){
    for(scanf("%lld%lld",&n,&w),i=1;i<=n;i++){
        scanf("%lld",&k);
        for(j=1;j<=k;j++) scanf("%lld",&arr[j]);
        arr[0]=arr[k+1]=0;
        d = w-k;
        while(st.size()) st.pop_back();
        for(j=0;j<=k+1;j++){
            while(st.size()){
                if(st.front().first+d<j) st.pop_front();
                else break;
            }
            while(st.size()){
                if(st.back().second<=arr[j]) st.pop_back();
                else break;
            }
            st.push_back(make_pair(j,arr[j]));
            ans[j]+=st.front().second;
        }
        int lst = k+1;
        while(st.size()){
            if(st.front().first+d>lst){
                upd(1,1,w,lst+1,st.front().first+d,st.front().second);
                lst = st.front().first+d;
                st.pop_front();
            }
            else st.pop_front();
        }
    }
    go(1,1,w);
    for(i=1;i<=w;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}