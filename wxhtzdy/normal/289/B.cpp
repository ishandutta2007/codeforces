#include <bits/stdc++.h>
using namespace std;
void ckmax(int &a,int b){a=max(a,b);}
int main(){	
	int n,m,d;
	scanf("%i %i %i",&n,&m,&d);
	int a[n][m],mx=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]),ckmax(mx,a[i][j]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if((mx-a[i][j])%d!=0){printf("-1");return 0;}
	vector<int> v;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)v.push_back(a[i][j]/d);
	sort(v.begin(),v.end());
	int ans=1e8,s=0,t=accumulate(v.begin(),v.end(),0);
	for(int i=0;i<(int)v.size();i++){
		ans=min(ans,i*v[i]-s+t-((int)v.size()-i)*v[i]);
		s+=v[i],t-=v[i];
	}
	printf("%i",ans);
	return 0;
}