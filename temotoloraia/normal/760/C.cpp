#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=2e5+5;
const ll INF=1e18;
int n,p[N],fix[N],b,ans,s,t,x,y,z;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>p[i];
	for (int i=1;i<=n;i++){
		cin>>b;
		s=(s+b)%2;
	}
	ans=ans+1-s;
	for (int i=1;i<=n;i++)
	if (fix[i]==0){
		if (i==p[i])z++;
		else y++;
		fix[i]=1;
		t=p[i];
		while (fix[t]==0){
			fix[t]=1;
			t=p[t];
		}
	}
	if (z+y==1)cout<<ans<<endl;
	else cout<<ans+z+y<<endl;
    return 0;
}