#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 1e5+5;
int st[26][3*MN], lz[26][3*MN], n, q, i, x, y, k, cnt[26];
string s;

inline void upd_lz(int idx,int i,int s,int e){
    if(!lz[idx][i]) return;
    st[idx][i]=(e-s+1)*(lz[idx][i]-1);
    if(s!=e) lz[idx][2*i]=lz[idx][2*i+1]=lz[idx][i];
    lz[idx][i]=0;
}

void upd(int idx,int i,int s,int e,int ss,int se,int val){
    upd_lz(idx,i,s,e);
    if(s>=ss&&e<=se){
        lz[idx][i]=val+1;
        upd_lz(idx,i,s,e);
    }
    else{
        if((s+e)/2<ss) upd(idx,2*i+1,(s+e)/2+1,e,ss,se,val), upd_lz(idx,2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(idx,2*i,s,(s+e)/2,ss,se,val), upd_lz(idx,2*i+1,(s+e)/2+1,e);
        else upd(idx,2*i,s,(s+e)/2,ss,se,val), upd(idx,2*i+1,(s+e)/2+1,e,ss,se,val);
        st[idx][i]=st[idx][2*i]+st[idx][2*i+1];
    }
}

int qu(int idx,int i,int s,int e,int ss,int se){
    upd_lz(idx,i,s,e);
    if(s>=ss&&e<=se) return st[idx][i];
    else if((s+e)/2<ss) return qu(idx,2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(idx,2*i,s,(s+e)/2,ss,se);
    else return qu(idx,2*i+1,(s+e)/2+1,e,ss,se)+qu(idx,2*i,s,(s+e)/2,ss,se);
}

int main(){
    cin >> n >> q >> s;
    for(i=1;i<=n;i++) upd(s[i-1]-'a',1,1,n,i,i,1);
    for(i=1;i<=q;i++){
        scanf("%d%d%d",&x,&y,&k);
        for(int j=0;j<26;j++){
            cnt[j]=qu(j,1,1,n,x,y);
            upd(j,1,1,n,x,y,0);
        }
        int f = x;
        if(k){
            for(int j=0;j<26;j++){
                if(!cnt[j]) continue;
                upd(j,1,1,n,f,f+cnt[j]-1,1);
                f += cnt[j];
            }
        }
        else{
            for(int j=25;j>=0;j--){
                if(!cnt[j]) continue;
                upd(j,1,1,n,f,f+cnt[j]-1,1);
                f += cnt[j];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            if(qu(j,1,1,n,i,i)) printf("%c",'a'+j);
        }
    }
    printf("\n");
    return 0;
}