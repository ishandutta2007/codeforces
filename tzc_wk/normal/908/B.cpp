#include <bits/stdc++.h>
using namespace std;
int n,m;
char g[53][53];
int d[4];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
string s;
int stx,sty;
bool instruction(){
	int cx=stx,cy=sty;
	for(int i=0;i<s.size();i++){
		cx+=dx[d[s[i]-'0']];
		cy+=dy[d[s[i]-'0']];
		if(cx<0||cx>=n||cy<0||cy>=m)	return false;
		if(g[cx][cy]=='#')	return false;
		if(g[cx][cy]=='E')	return true;
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='S')	stx=i,sty=j;
		}
	}
	cin>>s;
	int sum=0;
	for(d[0]=0;d[0]<4;d[0]++){
		for(d[1]=0;d[1]<4;d[1]++){
			if(d[0]==d[1])	continue;
			for(d[2]=0;d[2]<4;d[2]++){
				if(d[2]==d[0]||d[2]==d[1])	continue;
				for(d[3]=0;d[3]<4;d[3]++){
					if(d[3]==d[0]||d[3]==d[1]||d[3]==d[2])	continue;
					if(instruction())	sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
}//