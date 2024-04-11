#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans,ansx,ansy;
char mp[25][25];
void check(int x,int y){
	map<string,bool> has;
	for(int i=1;i <= n; i += x)
		for(int j=1;j<=m;j+=y){
			string cur;
			for(int ii=i,mx1=i+x;ii<mx1;ii++)
				for(int jj=j,mx2=j+y;jj<mx2;jj++)
					cur+=mp[ii][jj];
			if(has[cur])
				return;
			has[cur]=1;
			reverse(cur.begin(),cur. end());
			has[cur]=1;
			if(x==y){
				cur.clear();
				for(int jj=j,mx1=j+y;jj<mx1;jj++)
					for(int ii=i+x-1;ii>=i;ii--)
						cur+=mp[ii][jj];
				has[cur]=1;
				reverse(cur.begin(),cur.end());
				has[cur]=1;
			}
		}
	ans++;
	if(ansx==0||x*y < ansx * ansy)
		ansx=x,ansy=y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i ++)
		for(int j=1;j<=m;j ++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(n%i==0&&m%j==0)
				check(i,j);
	cout<<ans<<endl;
	cout<<ansx<<' '<<ansy<<endl;
	return 0;
}