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
const int MOD=1e9+7,N=1e5+5;
const ll INF=1e17;
int n,a[N],b[N],fix[N],x;
int main(){
	cin>>n;
	x=n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for (int i=2;i<=n;i++)b[i]=min(b[i-1],a[i]);
	for (int i=1;i<=n;i++){
	fix[a[i]]=1;
	if (a[i]==x){
		cout<<x<<" ";
		for (int i=x-1;i>=1;i--){
			if (fix[i]==0){
				x=i;
				break;
			}
			cout<<i<<" ";
		}
	}
	cout<<endl;
	}
    return 0;
}