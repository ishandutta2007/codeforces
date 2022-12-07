#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;
const int M = 450;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

char st[N+5];
int a[N+5],s[N+5];
int num[M*N+N+5];
int S,n;

In int id(int i,int k){
	return N + k * s[i] - i;
}

int main(){
//	freopen("CF1270F.in","r",stdin);
//	freopen("CF1270F.out","w",stdout);
	scanf("%s",st + 1);
	n = strlen(st + 1);
	for(rg int i = 1;i <= n;i++){
		a[i] = st[i] - '0';
		s[i] = s[i-1] + a[i];
	}
	S = ceil(sqrt(n));
//cout<<S<<endl;
//clock_t sta = clock();
	ll ans = 0;
	for(rg int k = 1;k <= S;k++){
		for(rg int i = 0;i <= n;i++)ans += num[id(i,k)]++;
		for(rg int i = 0;i <= n;i++)num[id(i,k)]--;		
	}
	a[n+1] = 2;
//clock_t T = clock();
//cout<<"part1: time="<<T-sta<<endl;
	for(rg int d = 1;d <= S;d++){
		int l = 1,r = 1;
		for(rg int i = 1;i <= n;i++){
			if(s[l] - s[i-1] != d){
				while(s[l] - s[i-1] < d && l <= n)l++;
				if(l == n + 1)break;
				r = l;
				while(a[r+1] == 0)r++;		
			}
			
//cout << "l="<<l<<" r="<<r<<endl;
			
			if ((r - i + 1) / d > S) ans += (r - i + 1) / d - max((l - i) / d, S);
		/*	int l = 0;
			while (l < n && s[l+1] < d) ++l;
			if (l == n) continue;
			int r = l + 1;
			while (r < n && s[r+1] <= d) ++r;
			for (int i = 0; i < n; i++) {
				if (s[r] - s[i] < d) {
					if (r == n) break;
					l = r;
					while (r < n && s[r+1] - s[i] <= d) ++r;
				}
				if ((r - i) / d > S) ans += (r - i) / d - max((l - i) / d, S);
			}*/
			
		}
	}
//clock_t T2 = clock();
//cout<<"part2: time="<<T2-T<<endl;
	write(ans),putchar('\n');
	return 0;
}