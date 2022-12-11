#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e3+10,M=60;
const int MOD=1e9+7,BASE=43;
const int inf=1e9+10;


int n,ntime,range;
int res[2][2][N][M];

int psum[3][N];

void prepare(){
    cin>>n>>ntime>>range;
    for(int i=0;i<=1;i++){
        int n1;
        cin>>n1;
        while (n1--){
            int pos;
            cin>>pos;
            psum[i][pos]=1;
        }
    }
    for(int i=1;i<=n;i++) psum[2][i]=psum[0][i]&psum[1][i];

    for(int i=0;i<=2;i++)
        for(int j=1;j<=n;j++) psum[i][j]+=psum[i][j-1];
}


template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
int solve(){
    int ans=0;
    for(int ctime=0;ctime<=ntime;ctime++){
        int cur=ctime&1,last=cur^1;
        memset(res[last],0,sizeof(res[last]));
        for(int p0=0;p0<=n;p0++)
            for(int p1=range;p1>=0;p1--) if (p0-p1>=0)
                for(int side=0;side<=1;side++){
                    int val=res[cur][side][p0][p1];
//                    cout<<ctime<<" "<<side<<" "<<p0<<" "<<p1<<" "<<val<<'\n';
                    maximize(ans,val);
                    maximize(res[last][side][p0][p1],val);

                    int np0=min(p0+range,n);
                    maximize(res[last][side][np0][min(np0-p0+p1,range)],val+psum[side][np0]-psum[side][p0]);


                    int np1=min(p0-p1+range,n);
                    int add=psum[side^1][np1]-psum[side^1][p0-p1]-(psum[2][p0]-psum[2][p0-p1]);
                    maximize(res[last][side^1][np1][np1-p0],val+add);


                    maximize(res[cur][side][p0+1][p1+1],val);
                    if (p1>0) maximize(res[cur][side][p0][p1-1],val);
                }
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}