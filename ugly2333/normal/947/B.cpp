//CF 947B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,a[N],b[N];
priority_queue<LL,vector<LL>,greater<LL> > Q;
int main()
{
	int i,x;
	LL w,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",b+i);
	w=0,x=0;
	for(i=1;i<=n;i=i+1){
		ans=0;
		Q.push(w+a[i]);
		x++;
		while(!Q.empty()&&Q.top()<=w+b[i]){
			ans+=Q.top()-w;
			Q.pop();
			x--;
		}
		w+=b[i];
		ans+=(LL)b[i]*x;
		cout<<ans<<' ';
	}
	return 0;
}