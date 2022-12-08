#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


const int B = 400;
int main(){
    int n;
    cin>>n;
    vector<int> a(303030);
    rep(i,n)cin>>a[i];
    vector<int> b(600);
    int q;
    cin>>q;
    while(q--){
        int type;
        scanf("%d",&type);
        if(type==1){
            int x,p;
            scanf(" %d%d",&x,&p);
            --x;
            int c = x/B;
            if(b[c]){
                rep(i,B)a[c*B+i]=max(a[c*B+i],b[c]);
                b[c]=0;
            }
            a[x]=p;
        }
        else {
            int p;
            scanf("%d",&p);
            rep(i,600)b[i]=max(b[i],p);
        }
    }
    rep(i,n)printf("%d ",max(a[i],b[i/B]));
    cout<<endl;
    return 0;
}