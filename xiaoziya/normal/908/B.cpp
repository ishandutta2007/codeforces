#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,T,ans,flg,ex,ey,sx,sy;
int p[5];
string s;
int a[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=m;j++){
			a[i][j]=s[j-1]=='#';
			if(s[j-1]=='S')
				sx=i,sy=j;
			if(s[j-1]=='E')
				ex=i,ey=j;
		}
	}
	cin>>s;
	p[1]=1,p[2]=2,p[3]=3,p[4]=4;
	int dx[5]={0,1,0,0,-1},dy[5]={0,0,1,-1,0};
	do{
		int x=sx,y=sy,flg=0;
		for(int i=0;i<s.size();i++){
			int c=p[s[i]-48+1],ux=x+dx[c],uy=y+dy[c];
			if(ux>=1&&ux<=n&&uy>=1&&uy<=m&&a[ux][uy]==0){
				x=ux,y=uy;
				if(x==ex&&y==ey)
					break;
			}
			else{
				flg=1;
				break;
			}
		}
		if(flg==0&&x==ex&&y==ey)
			ans++;
	}while(next_permutation(p+1,p+5));
	printf("%d\n",ans);
	return 0;
}