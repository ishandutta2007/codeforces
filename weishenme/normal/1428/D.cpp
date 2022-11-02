#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
const int N=100005;
int n,a[N],len,f[N];
vector<pii> ans;
vector<int> v1,v2,v3;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=n;i;i--)
		if (a[i]==1){
			ans.push_back(mp(i,++len));
			f[i]=len;
			v1.push_back(i);
		}
		else if (a[i]==2){
			if (!v1.size()){
				puts("-1");
				return 0;
			}
			ans.push_back(mp(i,f[v1[v1.size()-1]]));
			v1.pop_back();
			v2.push_back(i);
		}
		else if (a[i]==3){
			if (v3.size()){
				ans.push_back(mp(i,++len));
				ans.push_back(mp(v3[v3.size()-1],len));
				v3.pop_back();
				v3.push_back(i);
				continue;
			}
			if (v2.size()){
				ans.push_back(mp(i,++len));
				ans.push_back(mp(v2[v2.size()-1],len));
				v2.pop_back();
				v3.push_back(i);
				continue;
			}
			if (v1.size()){
				ans.push_back(mp(i,++len));
				ans.push_back(mp(v1[v1.size()-1],len));
				v1.pop_back();
				v3.push_back(i);
				continue;
			}
			puts("-1");
			return 0;
		}
	printf("%d\n",ans.size());
	for (pii i:ans)printf("%d %d\n",n-i.se+1,i.fi);
}