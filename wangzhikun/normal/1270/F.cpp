#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef __gnu_pbds::gp_hash_table<int,int> HashMap;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n;
char s[200020];
ll ans = 0;
int CC[45000040] = {0};
const int lb = 40000000;
void calcans(int rac){
	int cr =0;
	CC[lb+cr]+=1;
	for(int i=0;i<n;i++){
		if(s[i] == '1')cr-=rac-1;
		else cr+=1;
		ans+=CC[lb+cr];
		CC[lb+cr]+=1;
	}
	cr =0;
	CC[lb+cr]=0;
	for(int i=0;i<n;i++){
		if(s[i] == '1')cr-=rac-1;
		else cr+=1;
		CC[lb+cr]=0;
	}
}

int main() {
	cin>>s;
	n = strlen(s);
	const int blcsz = 200;
	for(int i=1;i<=blcsz;i++){
		calcans(i);
	}
	vector<int> cpo;
	cpo.push_back(-1);
	for(int i=0;i<n;i++){
		if(s[i] == '1')cpo.push_back(i);
	}
	cpo.push_back(n);
	for(int i=0;i<n;i++){
		int cp = lower_bound(cpo.begin(),cpo.end(),i)-cpo.begin();
		for(int j=cp;j<cpo.size()-1;j++){
			int cn = j-cp+1,cc = cpo[j],nxt = cpo[j+1];
			if(cn*blcsz>n)break;
			int cmake = (nxt-i)/cn,lbnd = max(blcsz,(cc+1-i+cn-1)/cn-1);
			//cout<<"! "<<cmake<<' '<<lbnd<<endl;
			ans+=max(cmake-lbnd,0);
		}
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/