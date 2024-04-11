#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
int a[300001];
int p[300001];
int c1[1048576];
int c2[1048576];
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	c2[0]++;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		p[i]=p[i-1]^a[i];
		if(i%2==1){
			ans+=c1[p[i]]++;
		}
		else{
			ans+=c2[p[i]]++;
		}
	}
	cout << ans << endl;
}