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
const int N = 5e5 + 10;

int n;
__int128 ans=linf,prm[]{2,3,5,7,11,13,17,19,23,29};
void dfs(int d,__int128 num,int cnt){//
    if(cnt==n){
        ans=min(ans,num);
        return;
    }
    for(int i=1;;i++){//
        num*=prm[d];
        if(num>ans||cnt*(i+1)>n)break;
        dfs(d+1,num,cnt*(i+1));
    }
}
void o(__int128 a){
    if(a>9)o(a/10);
    putchar('0'+a%10);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n;
	dfs(0,1,1);
    o(ans);
	return 0;
}