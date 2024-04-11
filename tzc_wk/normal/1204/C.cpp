#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
int n,dist[105][105],p[1000005],m,cnt=0;
char s[105];
bool del[1000005];
vector<int> ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			dist[i][j]=s[j]-'0';
			if(dist[i][j]==0&&i!=j)	dist[i][j]=1e6;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)	cout<<dist[i][j]<<" ";
//		cout<<endl;
//	}
	cin>>m;
	for(int i=1;i<=m;i++)	cin>>p[i];
	int last=1,sum=dist[p[1]][p[2]];
	for(int i=2;i<m;i++){
		int j=last;
//		cout<<i<<" "<<j<<" "<<sum<<endl;
		if(dist[p[j]][p[i+1]]==sum+dist[p[i]][p[i+1]])
			del[i]=1;
		if(!del[i])	last=i,sum=0;
		sum+=dist[p[i]][p[i+1]];
	}
	for(int i=1;i<=m;i++)	if(!del[i])	cnt++,ans.push_back(i);
	cout<<cnt<<endl;
	for(int i=0;i<ans.size();i++)	cout<<p[ans[i]]<<" ";
	return 0;
}
/*
4
0100
0010
0001
1000
8
1 2 3 4 1 2 3 4
*/