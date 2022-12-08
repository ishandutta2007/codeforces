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

int main(){
    int q;
    cin>>q;
    while(q--){
        int b,w;
        cin>>b>>w;
        if(b>3*w+1||w>3*b+1){
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<endl;
            int x = min(b,w);
            rep(i,2*x){
                printf("%d %d\n",2,i+2);
            }
            b-=x;
            w-=x;
            rep(i,w){
                if(i<x)printf("%d %d\n",1,2*i+3);
                else if(i<2*x)printf("%d %d\n",3,2*i+3-2*x);
                else printf("2 %d\n",2*x+2);
            }
            rep(i,b){
                if(i<x)printf("%d %d\n",1,2*i+2);
                else if(i<2*x)printf("%d %d\n",3,2*i+2-2*x);
                else printf("2 1\n");
            }
        }
    }
    return 0;
}