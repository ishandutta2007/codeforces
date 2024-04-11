#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 600+10;
const int mod=998244353;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            mp[a]++;
        }
        cout<<n-mp.begin()->se<<endl;
    }
}