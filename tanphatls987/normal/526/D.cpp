#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,k,f[N],h[N],pre[N];
string s;
int main(){
    cin>>n>>k>>s;
    f[0]=-1;
    REP(i,1,n){
        int r=f[i-1];
        while (r!=-1&&s[i]!=s[r+1]) r=f[r];
        f[i]=r+(s[i]==s[r+1]);
    }
    FOR(j,1,n){
        bool ok=true;
        for(int i=j+j-1;i<n&&ok;i+=j) {
            int len=i-f[i];
            if (len!=j) ok=false;
            if ((i+1)/j%k==0&&ok) {
                int L=i+1,R=min(i+(i+1)/k,n-1);
                while (L<=R){
                    int M=(L+R)/2;
                    if (f[M]-f[i]!=M-i) R=M-1;
                    else L=M+1;
                }
                h[i]++,h[L]--;
            }
        }
    }
    if (k==1) h[0]=1;
    REP(i,1,n) h[i]+=h[i-1];
    REP(i,0,n) if (h[i]) printf("1");
    else printf("0");
}