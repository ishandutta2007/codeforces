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
const int N = 1e6 + 10;
const int mod=998244353;
ll ans[N],pre[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);

	for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            ans[j]++;
        }
	}
	for(int i=1;i<N;i++){
        (ans[i]+=pre[i-1])%=mod;
        pre[i]=(pre[i-1]+ans[i])%mod;
	}
	int n;cin>>n;
	cout<<ans[n];
}