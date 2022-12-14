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
typedef array<int,3>tri;
tri arr[N];
int pre[N];
vi v{0};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
//    int n;cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>arr[i][0]>>arr[i][1];
//        arr[i][2]=i;
//    }
    int n,t;cin>>n>>t;

    for(int cas=0;cas<t;cas++){
        int a;cin>>a;
        if(!cas){
            for(int i=20;i<=n;i+=20){
                cout<<"? 1 "<<i<<endl;
                int a;cin>>a;
                v.push_back(i-a);
            }
        }
        int r=lower_bound(v.begin(),v.end(),a)-v.begin();
        r*=20;
        int l=r-19;
        r=min(r,n);
        while(r-l>0){
            cout<<"? 1 "<<mid<<endl;
            int b;cin>>b;
            if(mid-b>=a)r=mid;
            else l=mid+1;
        }
        cout<<"! "<<r<<endl;
        for(int i=(l-1)/20+1;i<v.size();i++)v[i]--;
    }
	return 0;
}