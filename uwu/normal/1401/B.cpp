#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int x1,y1,z1,x2,y2,z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        ll tot=0; int temp;
        temp=min(z1,y2); tot+=2*temp; z1-=temp, y2-=temp; //2,1
        temp=min(z1,z2); z1-=temp, z2-=temp; //2,2
        temp=min(x1,z2); x1-=temp, z2-=temp; //0,2
        temp=min(y1,y2); y1-=temp, y2-=temp; //1,1
        temp=min(y1,x2); y1-=temp, x2-=temp; //1,0
        tot-=min(y1,z2)*2;
        cout << tot << '\n';
    }
}