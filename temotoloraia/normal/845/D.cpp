#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int INF=1e9;
int main() {
    int n;
    cin>>n;
    int S,o=0;
    stack<int>Q;
    int ans=0;
    while (n--){
            //cout<<ans<<" HELLO"<<endl;
        int x,y;
        cin>>x;
        if (x==1){
            cin>>y;
            S=y;
            if (Q.size()==0)continue;
            //cout<<y<<"    "<<S<<" "<<ans<<" "<<Q.top()<<endl;
            //cout<<S<<" ";
            while (Q.top()<S){
                ans++;
                //cout<<Q.top()<<" ";
                Q.pop();
                if (Q.size()==0)break;
            }
            //cout<<"HELLO\n";
            continue;
        }
        if (x==2){
            ans+=o;
            o=0;
            continue;
        }
        if (x==3){
            cin>>y;
            if (S>y)ans++;
            else Q.push(y);
            continue;
        }
        if (x==4){
            o=0;
            continue;
        }
        if (x==5){
            Q.push(INF);
            continue;
        }
        if (x==6){
            o++;
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}