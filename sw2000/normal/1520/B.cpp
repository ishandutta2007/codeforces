#include<bits/stdc++.h>
#define lo (o<<1)
#define ro (o<<1|1)
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const int mod = 220000607;
vi v;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int a=0;
            for(int k=0;k<i;k++){
                a=a*10+j;
            }
            v.push_back(a);
        }
    }
    v.push_back(inf);
    int _;cin>>_;
    while(_--){
        int a;cin>>a;
        int ans=0;
        for(auto i:v){
            if(i<=a)ans++;
            else break;
        }
        cout<<ans<<endl;
    }
	return 0;
}