#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 150005;

int T, n, x, y;

int main(){
	//freopen("in.txt","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d%d",&x,&y);
		if(x>y) printf("%d\n",x+y);
		else printf("%d\n",y-(y%x)/2);
	}
}