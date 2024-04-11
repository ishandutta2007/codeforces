#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int P = 1e9+7;
const int N = 1e6+5;
const double PI = acos(-1);
mt19937 rng(time(0));

char s[N], ans[N], w[N<<1];
int n, T, m, l, r, rr[N<<1];

void work(int l, int r, char s[]){
	int ma = 0, n = r-l+1; 
	rep(i,1,n) w[i<<1] = s[i+l-1];
	rep(i,0,n) w[i<<1|1] = -1;
	w[0] = -2, w[n+1<<1] = -3;
	//rep(i,0,n+1<<1) cout<<(int)w[i];cout<<endl;
	int mx=0, p=0;
	rep(i,2,n<<1){
		rr[i] = max(min(mx-i,p*2-i>0?rr[2*p-i]:0),1);
		while(w[i-rr[i]]==w[i+rr[i]])++rr[i];
		if(i+rr[i]>mx)mx=(p=i)+rr[i];
		//cout<<i<<" "<<rr[i]<<endl;
		if(rr[i]==i) ma = max(ma, rr[i]-1);
	}
	
	if(ma>m){
		m = ma;
		rep(i,l,l+m-1) ans[i] = s[i];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d\n",&T);
	while(T--){
		scanf("%s\n", s+1);
		n = strlen(s+1);
		m = l = r = 0;
		rep(i,1,n/2){
			if(s[i] != s[n+1-i]){
				l = i, r = n+1-i;
				break;
			}
		}
		if(!l){
			printf("%s\n",s+1);
			continue;
		}
		work(l, r, s);
		reverse(s+l,s+r+1);
		work(l, r, s);
		
		rep(i,1,l-1) ans[i] = s[i];
		rep(i,r+1,n) ans[l+m+i-r-1] = s[i];
		ans[l+m+n-r] = '\0';
		printf("%s\n", ans+1);
	}
	return 0;
}