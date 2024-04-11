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
const int mod = 1e9+7;

int main(){
    int n,t;cin>>n>>t;
    int k;cin>>k;
    int l=1,r=n;
    while(l!=r){
        cout<<"? 1 "<<mid<<endl;
        int a;cin>>a;
        if(mid-a>=k)r=mid;
        else l=mid+1;
    }
    cout<<"! "<<r;
	return 0;
}