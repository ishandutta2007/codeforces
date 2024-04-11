#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

string s;
LL l, r, y = 2e9, a[100], b[100], n;

int pw(int x, int n){
	LL res = 1;
	rep(i,1,n)res*=x;
	return res;
}

int main(){
	/*#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif*/
	cin>>s;
	while(s!="end"){
		l = 1e9; r = 2e9;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			cout<<"? "<<l<<" "<<mid<<endl;
			fflush(stdout);
			cin>>s;
			if(s=="x")
				r = mid;
			else
				l = mid;
		}
		int backr = r; n = 0;
		for(int i=2;i*i<=r;++i)if(r%i==0){
			int cnt=0;
			while(r%i==0){
				++cnt;r/=i;
			}
			a[++n] = i;
			b[n] = cnt;
		}
		if(r>1){
			a[++n] = r;
			b[n] = 1;
		}
		
		r = backr;
		//rep(i,1,n)cout<<a[i]<<" "<<b[i]<<endl;
		LL down = 1, up = r;
		rep(i,1,n){
			l = 0; r = b[i];
			while(l<r){
				int mid = (l+r)>>1;
				LL x = pw(a[i],b[i]-mid);
				cout<<"? "<<up/x-1<<" "<<up/x<<endl;
				fflush(stdout);
				cin>>s;
				if(s=="x") r=mid; else l=mid+1;
			}
			down *= pw(a[i],l); up /= pw(a[i],b[i]-l);
			//cout<<down<<" "<<up<<endl;
		}
		cout<<"! "<<down<<endl;
		cin>>s;
		if(s=="mistake")return 0;
	}
	return 0;
}