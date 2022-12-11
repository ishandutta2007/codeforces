#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n;
vector<int>ans;
void solve(int l,int r){
	int now=(r-l+n)%n;
	for(int i=0;i<=((now+1)>>1)-1;i++){
		for(int o=(r-1-i+n)%n;o!=l+i;o=(o-1+n)%n)ans.push_back(o%n);
		for(int o=l+i;o!=r-i;o=(o+1)%n)ans.push_back(o%n);
	}
	for(int i=0;i<=(now>>1)-1;i++)ans.push_back((l+i)%n);
}
int main(){
    scanf("%d",&n);
	solve(0,n-1);
	if(!(n&1))solve(n>>1,(n>>1)-1);
	else solve((n>>1)+1,(n>>1)-1);
	solve(0,n-1);
	printf("%d\n",(int)ans.size());
    for(int i:ans)printf("%d ",i);
	return 0;
}