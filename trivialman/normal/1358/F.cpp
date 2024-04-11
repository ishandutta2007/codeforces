#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

string ans = "";
LL a[N], b[N], c[N];
int n;

bool equal(LL a[], LL b[]){
	rep(i,1,n) if(a[i]!=b[i]) return false;
	return true;
}

bool ge(LL a[], LL b[]){
	rep(i,1,n) if(a[i]>b[i]) return true;
	return false;
}

bool rev(LL a[]){
	rep(i,1,n) c[i] = a[i];
	reverse(c+1,c+n+1);
	rep(i,1,n) if(a[i]<c[i]) return false; else if(c[i]<a[i]) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",a+i);
	rep(i,1,n) scanf("%lld",b+i);
	
	bool flag = false;
	if (rev(a)) reverse(a+1, a+n+1), flag = true;
	if (rev(b)) reverse(b+1, b+n+1), ans += 'R';
	
	rep(i,1,200001){
		if (equal(a, b)) {
			if (flag) ans += 'R';
			reverse(ans.begin(), ans.end());
			printf("SMALL\n%d\n",ans.size());
			cout<<ans;
			exit(0);
		}
		
		rrep(i,n,2) b[i] -= b[i-1];
		ans += 'P';
		if (rev(b)) reverse(b+1,b+n+1), ans += 'R';
		if (ge(a, b)) {
			cout<<"IMPOSSIBLE\n";
			exit(0);
		}
	}
	
	if(n>2){
		LL num = 200001;
		while(1){
			if (equal(a, b)) {
				printf("BIG\n%d\n",num);
				return 0;
			}
			
			rrep(i,n,2) b[i] -= b[i-1];
			if (rev(b)) reverse(b+1,b+n+1);
			if (ge(a, b)) {
				cout<<"IMPOSSIBLE\n";
				exit(0);
			}
			num++;
		}
	}else{
		LL num = 200001;
		//cout<<b[1]<<" "<<b[2]<<" "<<num<<endl;
		while(a[1]<b[1]){
			num += b[2]/b[1];
			b[2] %= b[1];
			swap(b[1], b[2]);
		}
		if (a[1]==b[1] && a[2]<=b[2] && (b[2]-a[2])%a[1]==0){
			num += (b[2]-a[2])/a[1];
			printf("BIG\n%lld\n",num);
		}else cout<<"IMPOSSIBLE\n";
	}
	return 0;
}