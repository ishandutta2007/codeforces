#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<int>now,way;
const int N=110000;
int A[N],n,ans;
void change(){
	int len=n; n=0; A[0]=0;
	for (int i=1;i<=len;i++)
		if (A[i]!=0&&A[i]!=A[n]) A[++n]=A[i];
}
void solve(int k1){
	//cout<<"fa "<<k1<<" "<<n<<endl;
	//for (int i=0;i<way.size();i++) cout<<way[i]<<" "; cout<<endl;
	//for (int i=1;i<=n;i++) cout<<A[i]<<" "; cout<<endl;
	if (way.size()>=ans) return;
	if (n==0){
		ans=way.size(); now=way; return;
	}
	if (n==1){
		if (A[1]==1){
			way.push_back((1<<k1)); n=0; solve(k1+1); n=1; way.pop_back();
			return;
		}
		if (A[1]==-1){
			way.push_back(-(1<<k1)); n=0; solve(k1+1); n=1; way.pop_back();
			return;
		}
	}
	int B[N];
	int pren=n; for (int i=1;i<=n;i++) B[i]=A[i];
	int flag=0;
	for (int i=1;i<=n;i++) if (abs(A[i])&1) flag=1;
	if (flag==0){
		for (int i=1;i<=n;i++) A[i]/=2;
		solve(k1+1);
	} else {
		way.push_back((1<<k1));
		for (int i=1;i<=n;i++){
			if (abs(A[i])&1) A[i]--; A[i]/=2;
		}
		change(); solve(k1+1);
		way.pop_back(); n=pren;
		for (int i=1;i<=n;i++) A[i]=B[i];
		way.push_back(-(1<<k1));
		for (int i=1;i<=n;i++){
			if (abs(A[i])&1) A[i]++; A[i]/=2;
		}
		change(); solve(k1+1); way.pop_back();
	} 
	n=pren;
	for (int i=1;i<=n;i++) A[i]=B[i];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1); change(); ans=19;
	solve(0);
	printf("%d\n",ans);
	for (int i=0;i<now.size();i++) printf("%d ",now[i]);
}