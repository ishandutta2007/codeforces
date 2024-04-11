#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],s1[1005][1005],s2[1005][1005],s3[1005][1005],s4[1005][1005],s5[1005][1005],s6[1005][1005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++){
		map<int,int> s;
		for(int j=0;j<m;j++)	s[a[i][j]]=0;
		int cnt=0;
		for(map<int,int>::iterator it=s.begin();it!=s.end();it++){
			cnt++;
			s[(*it).first]=cnt;
		}
		for(int j=0;j<m;j++){
			s1[i][j]=s[a[i][j]];
			s3[i][j]=s.size()-s[a[i][j]];
			s5[i][j]=s.size();
		}
	}
	for(int j=0;j<m;j++){
		map<int,int> s;
		for (int i=0;i<n;i++)	s[a[i][j]]=0;
		int cnt=0;
		for(map<int,int>::iterator it=s.begin();it!=s.end();it++){
			cnt++;
			s[(*it).first]=cnt;
		}
		for(int i=0;i<n;i++){
			s2[i][j]=s[a[i][j]];
			s4[i][j]=s.size()-s[a[i][j]];
			s6[i][j]=s.size();
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int sum=s5[i][j]+s6[i][j]-1;
			sum-=min(s1[i][j],s2[i][j])-1;
			sum-=min(s3[i][j],s4[i][j]);
			printf("%d ",sum);
		}
		printf("\n");
	}
	return 0;
}