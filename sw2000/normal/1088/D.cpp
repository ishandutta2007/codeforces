#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
//#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

int f,a,c,d,cc=1,dd=2;
void q(){
    cout<<"? "<<c<<' '<<d<<endl;
//    if((cc^c)<(dd^d))a=-1;
//    if((cc^c)==(dd^d))a=0;
//    if((cc^c)>(dd^d))a=1;
    cin>>a;
//    cout<<a<<endl;
}
int main(){
//    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    q();
    f=a<0;
    for(int i=29;~i;i--){
        c^=1<<i;
        d^=1<<i;
        q();
        if(a<0&&f==0||a>=0&&f==1){
            if(f)c^=1<<i;
            else d^=1<<i;
            q();
            f=a<0;
        }
        else{
            c^=1<<i;
            q();
            if(a<0)d^=1<<i;
            else c^=1<<i;
        }
    }
    cout<<"! "<<c<<' '<<d<<endl;
	return 0;
}