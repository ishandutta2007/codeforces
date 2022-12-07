#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = b; i >= a; i--)
 
using namespace std;
 
const int N=100005;
 
int n,q,s[N], jump[N][20];
 
int main() {
	rep(i,2,N-1)
		if(!s[i]) 
			rep(j,1,(N-1)/i)
				s[i*j]=i;
	cin>>n>>q;
	map<int,int>last;
	int M=0;
	rep(i,1,n) {
		int x;
		cin>>x;
		int R=0,y=x;
		while(x>1){
			R=max(R, last[s[x]]);
			x /= s[x];
		}
		M=max(M,R);
		jump[i][0] = M;
		rep(bit,1,19)
			jump[i][bit]=jump[jump[i][bit-1]][bit-1];
		while(y>1){
			last[s[y]] = i;
			y /= s[y];
		}
	}
	rep(i,1,q) {
		int l,r;
		cin>>l>>r;
		int ans=0;
		per(bit,0,19) {
			if(jump[r][bit] >= l) {
				ans+=(1<<bit);
				r = jump[r][bit];
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}