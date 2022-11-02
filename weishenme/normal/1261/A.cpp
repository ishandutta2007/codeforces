#include<bits/stdc++.h>
using namespace std;
#define int long long
#define se second
#define fi first
#define mp make_pair
const int N=2005;
vector<pair<int,int> >ans;
int T,n,k;
char s[N];
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&k);
		ans.clear();
		scanf("%s",s+1);
		for (int i=1;i/2+2<=k;i+=2){
			if (s[i]=='('){
				for (int k=i+1;k<=n;k++)
					if (s[k]==')'){
						if (i+1!=k)ans.push_back(mp(i+1,k));
						reverse(s+i+1,s+k+1);	
						break;
					}
			}
			else {
				for (int k=i+1;k<=n;k++)
					if (s[k]=='('){
						ans.push_back(mp(i,k));
						reverse(s+i,s+k+1);
						break;
					}
			}
		}
		for (int i=(k-1)*2+1;i<=n;i++)
			if (s[i]==')')
				for (int j=i+1;j<=n;j++)
					if (s[j]=='('){
						reverse(s+i,s+j+1);
						ans.push_back(mp(i,j));
						break;
					}
		printf("%lld\n",(int)ans.size());			
		for (int i=0;i<ans.size();i++)printf("%lld %lld\n",ans[i].fi,ans[i].se);
	}
	return 0;
}