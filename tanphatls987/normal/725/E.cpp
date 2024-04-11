#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

typedef unsigned long long ull;

const int N=2e5+10;

int sum,n;
int a[N],h[N];
struct BIT{
    int b[N];
    void add(int x,int v){
        while (x<=sum){
            b[x]+=v;
            x+=x&-x;
        }
    }
    int get(int x){
        int ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
    int findfre(int pos){
        int val=get(pos);
        if (!val) return pos+1;
        int cur=0;
        for(int i=19;i>=0;i--) {
            int cpos=cur+(1<<i);
            if (cpos>pos)  continue;
            if (val>b[cpos]){
                cur=cpos;
                val-=b[cpos];
            }
        }
        return cur+1;
    }
}mbit;

vector <ii> ret;
bool check(int use){
    ret.clear();
    h[use]++;
    mbit.add(use,1);
    int cur=sum;
    while (cur){
        int idx=mbit.findfre(cur);
        if (idx>cur) return 1;
        int take=min(cur/idx,h[idx]);
        cur-=take*idx;
        h[idx]-=take;
        ret.push_back(ii(idx,take));
        mbit.add(idx,-take);
    }
    for(auto i:ret) {
        h[i.X]+=i.Y;
        mbit.add(i.X,i.Y);
    }
    h[use]--;
    mbit.add(use,-1);
    return 0;
}
int main(){
    scanf("%d%d",&sum,&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) {
        mbit.add(a[i],1);
        h[a[i]]++;
    }
    for(int use=1;use<=sum;use++)
        if (check(use)) {
            cout<<use;
            return 0;
        }
    cout<<"Greed is good";
}