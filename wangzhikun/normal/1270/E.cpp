#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,x[1010],y[1010];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(x[i]);read(y[i]);
	}
	for(int i=1;i<n;i++){
		x[i]-=x[0];
		y[i]-=y[0];
	}
	x[0] = y[0] = 0;
	while(1){
		int cnt[2] = {0};
		for(int i=0;i<n;i++){
			cnt[(abs(x[i])%2+abs(y[i])%2)%2]+=1;
		//	cout<<x[i]<<' '<<y[i]<<endl;
		}
		//cout<<"==="<<endl;
		if(cnt[0]!=0 && cnt[1]!=0){
			cout<<cnt[0]<<endl;
			for(int i=0;i<n;i++){
				if((abs(x[i])%2+abs(y[i])%2)%2 == 0){
					cout<<i+1;
					cnt[0]--;
					if(cnt[0])cout<<' ';
				}
			}
			cout<<endl;
			return 0;
		}
		
		for(int i=1;i<=n;i++){
			int nx = (x[i]+y[i])/2,ny = (x[i]-y[i])/2;
			x[i] = nx;
			y[i] = ny;
		}
	}
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/