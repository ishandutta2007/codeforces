#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=107;
int t,r,c,k;
char s[maxn][maxn];
int ans[maxn][maxn];

void print(int u){
    if (u>k) u--;
    if (u<=10) printf("%c",'0'+u-1);
    if (u>10&&u<=36) printf("%c",'a'+u-11);
    if (u>36) printf("%c",'A'+u-37);
}
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d%d%d",&r,&c,&k);
        rep(i,r) cin>>s[i];
        int sum=0,ret=0;
        rep(i,r){
            rep(j,c){
                if (s[i][j]=='R') sum++;
            }
        }         
        ret=sum/k;
        int rem=sum-ret*k,count=0,cnt=1;
        rep(i,r){
            if (i%2){
                rep(j,c){
                    ans[i][j]=cnt;
                    if (s[i][j]=='R') count++;
                    if (count>=ret+(cnt>=k+1-rem)){
                        cnt++;
                        if (count>ret) rem--;
                        count=0;
                    }
                }
            }
            else{
                for (int j=c-1;j>-1;--j){
                    ans[i][j]=cnt;
                    if (s[i][j]=='R') count++;
                    if (count>=ret+(cnt>=k+1-rem)){
                        cnt++;
                        if (count>ret) rem--;
                        count=0;
                    }
                }
            }
        }
        rep(i,r){
            rep(j,c){
                print(ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}