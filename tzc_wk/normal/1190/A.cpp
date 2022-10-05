#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p[100005],k;
int q[100005],head=1,tail=1,del=0,ans=0;
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>p[i];
	while(tail<=m){
		ans++;
		int tmp=tail;
		int end=(p[head]-del-1)/k*k+k;
//		cout<<end<<endl;
		while(tail<=m&&p[tail]-del<=end)	tail++;
		del+=tail-tmp;
//		cout<<tail<<" "<<del<<endl;
		head=tail;
	}
	cout<<ans<<endl;
	return 0;
}//