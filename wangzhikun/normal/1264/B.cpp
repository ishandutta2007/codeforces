#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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

int fnd = 0;
int req[4];
int mx = -10,mi = 10;
void gen(vector<int> cc){
	if(fnd)return;
	int cadd[4] = {0},cnt[4] = {0};
	for(auto ct:cc){
		cnt[ct]++;
	}
	for(int i=mi;i<mx;i++){
		if(req[i]-cnt[i]<0)return;
		cadd[i]+=req[i]-cnt[i];
		cnt[i]+=cadd[i];
		cnt[i+1]+=cadd[i];
	}
	if(cnt[mx]!=req[mx])return;
	fnd = 1;
	vector<int> ans;
	for(int i=0;i<cc.size();i++){
		ans.push_back(cc[i]);
		if(i+1<cc.size() && cc[i] == cc[i+1]-1){
			for(int j=0;j<cadd[cc[i]];j++){
				ans.push_back(cc[i]+1);
				ans.push_back(cc[i]);
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i!=ans.size()-1){
			cout<<' ';
		}
	}
	cout<<endl;
}

int main() {
	
	for(int i=0;i<4;i++){
		cin>>req[i];
		if(req[i]){
			mx = max(mx,i);
			mi = min(mi,i);
		}
	}
	if(mx == mi){
		if(req[mx] == 1){
			cout<<"YES"<<endl;
			cout<<mx<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		return 0;
	}
	vector<int> cu;
	cu.push_back(mi+1);
	for(int i=mi;i<=mx;i++)cu.push_back(i);
	gen(cu);
	cu.push_back(mx-1);
	gen(cu);
	cu.clear();
	for(int i=mi;i<=mx;i++)cu.push_back(i);
	gen(cu);
	cu.push_back(mx-1);
	gen(cu);
	if(!fnd){
		cout<<"NO\n";
	}
	return 0;
}