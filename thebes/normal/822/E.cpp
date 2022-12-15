#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MN = 1e5+5, mod = 1e9+9;
int N, M, X, i, j, a[MN], b[MN], hsh[MN][2], pw[MN]={1}, cur, lo, hi, mid;
string s, t;
inline int get(int x,int y,int id){
    int ret=(hsh[y][id]-1LL*hsh[x-1][id]*pw[y-x+1])%mod;
    return ret<0?ret+mod:ret;
}

int main(){
    scanf("%d",&N);
    cin >> s;
    scanf("%d",&M);
    cin >> t;
    scanf("%d",&X);
    for(i=1;i<MN;i++)
        pw[i]=133LL*pw[i-1]%mod;
    for(i=0;i<N;i++)
        hsh[i+1][0]=(133LL*hsh[i][0]+s[i]-'a'+1)%mod;
    for(i=0;i<M;i++)
        hsh[i+1][1]=(133LL*hsh[i][1]+t[i]-'a'+1)%mod;
    memset(b,0x3f,sizeof(b));
    b[N]=M;
    for(;X;X--){
        cur = 1<<30;
        memset(a,0x3f,sizeof(a));
        for(i=N;i>=1;i--){
            cur = min(cur,b[i]);
            lo=1, hi=min(i,cur)+1;
            while(lo<hi){
                mid=(lo+hi)>>1;
                if(get(i-mid+1,i,0)==get(cur-mid+1,cur,1)) lo=mid+1;
                else hi=mid;
            }
            lo--;
            a[i]=min(a[i],cur);
            a[i-lo]=min(a[i-lo],cur-lo);
        }
        swap(a,b);
    }
    int mn = 1<<30;
    for(i=0;i<=N;i++)
        mn = min(mn, b[i]);
    printf("%s\n",mn?"NO":"YES");
    return 0;
}