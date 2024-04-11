#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int tab[100001][17][6];
int n,m,k;
vector<int> get(int l,int r) { //[l,r]
    int num = 0;
    while(1<<num <= (r-l+1)) {
        ++num;
    }
    --num;
    vector<int> ans(m);
    for(int i=0;i<m;i++) {
        ans[i]=max(tab[l][num][i], tab[r-(1<<num)+1][num][i]);
    }
    return ans;
}
bool works(int l, int r) {
    vector<int> t = get(l,r);
    ll temp = 0;
    for(int i=0;i<m;i++) temp+=t[i];
    return temp<=k;
}
int binarySearch(int lo, int hi,int idx) {
    int mid = (lo+hi)/2;
    if(works(idx,mid)) {
        if(mid+1>=n || !works(idx,mid+1)) return mid;
        return binarySearch(mid+1,hi,idx);
    }
    return binarySearch(lo,mid-1,idx);

}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    int val[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            scanf("%d",&val[i][j]);
    }
    //max[i,i+2^j][k]
    for(int j=0;j<17;j++) {
        for(int i=0;i<n;i++) {
            for(int l=0;l<m;l++) {
                if(j==0) tab[i][j][l] = val[i][l];
                else if(i+(1<<j)<=n){
                    tab[i][j][l] = max(tab[i][j-1][l],tab[i+(1<<(j-1))][j-1][l]);
                }
            }
        }
    }
    int ans = 0;
    vector<int> ret(m);
    for(int i=0;i<n;i++) {
        if(!works(i,i)) continue;
        int r = binarySearch(i,n-1,i);
        if(r-i+1>ans) {
            ans = r-i+1;
            ret = get(i,r);
        }
    }
    for(auto &it : ret) printf("%d ",it);
}