#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int x[4],y[4];
int cnt[N],cnt1[N];
void solve(){
	int n=in();
	for(int i=1;i<=3;i++)cin>>x[i]>>y[i],cnt[x[i]]++,cnt1[y[i]]++;
	int X,Y;
	X=cnt[x[1]]==2?x[1]:x[2];
	Y=cnt1[y[1]]==2?y[1]:y[2];
	int a,b;
	cin>>a>>b;
	if(a%2!=X%2&&b%2!=Y%2)puts("NO");
	else if(X!=a&&Y!=b&&(X==1||X==n)&&(Y==1||Y==n))puts("NO");
	else puts("YES");
	for(int i=1;i<=3;i++)cnt[x[i]]=0,cnt1[y[i]]=0;
}
int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int t=in();
	while(t--)solve(); 
	return 0;
}