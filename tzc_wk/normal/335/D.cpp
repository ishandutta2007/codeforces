/*
Contest: -
Problem: Codeforces 335D
Author: tzc_wk
Time: 2020.10.14
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
int n,s1[3005][3005],s2[3005][3005],s3[3005][3005],s4[3005][3005],s5[3005][3005];
vector<int> l[3005],r[3005];
inline int areasum(int x1,int y1,int x2,int y2){
	if(x2>3000||y2>3000) return -1;
	return s1[x2][y2]-s1[x1-1][y2]-s1[x2][y1-1]+s1[x1-1][y1-1];
}
inline int border_row1(int y,int x1,int x2){
	if(x2>3000) return -1;
	return s2[x2][y]-s2[x1-1][y];
}
inline int border_row2(int y,int x1,int x2){
	if(x2>3000) return -1;
	return s4[x2][y]-s4[x1-1][y];
}
inline int border_col1(int x,int y1,int y2){
	if(x>3000||y2>3000) return -1;
	return s3[x][y2]-s3[x][y1-1];
}
inline int border_col2(int x,int y1,int y2){
	if(x>3000||y2>3000) return -1;
	return s5[x][y2]-s5[x][y1-1];
}
struct bar{
	int x1,y1,x2,y2;
} b[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1++;y1++;
		b[i].x1=x1;b[i].y1=y1;b[i].x2=x2;b[i].y2=y2;
		s1[x1][y1]++;s1[x2+1][y1]--;
		s1[x1][y2+1]--;s1[x2+1][y2+1]++;
		s2[x1][y1]++;s2[x2+1][y1]--;
		s4[x1][y2]++;s4[x2+1][y2]--;
		s3[x2][y1]++;s3[x2][y2+1]--;
		s5[x1][y1]++;s5[x1][y2+1]--;
		l[x1].push_back(y1);r[x1].push_back(y2);
	}
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s1[i][j]+=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s1[i][j]+=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s2[i][j]+=s2[i-1][j];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s2[i][j]+=s2[i-1][j];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s3[i][j]+=s3[i][j-1];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s3[i][j]+=s3[i][j-1];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s4[i][j]+=s4[i-1][j];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s4[i][j]+=s4[i-1][j];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s5[i][j]+=s5[i][j-1];
	for(int i=1;i<=3002;i++) for(int j=1;j<=3002;j++) s5[i][j]+=s5[i][j-1];
	bool flg=0;int x1=0,y1=0,x2=0,y2=0;
	for(int i=1;i<=3002;i++) for(int j=0;j<l[i].size();j++){
		for(int t=0;t<r[i].size();t++){
			int up=r[i][t],down=l[i][j];
			if(down>up) continue;int x=up-down+1;
			if(areasum(i,down,i+x-1,up)==(x*x)&&border_row1(down,i,i+x-1)==x
			&&border_row2(up,i,i+x-1)==x&&border_col1(i+x-1,down,up)==x&&border_col2(i,down,up)==x){
				flg=1;x1=i;y1=down;x2=i+x-1;y2=up;
				break;
			}
		}
		if(flg) break;
	}
	if(!flg) printf("NO\n");
	else{
		printf("YES\n");vector<int> ans;
//		printf("%d %d %d %d\n",x1,y1,x2,y2);
		for(int i=1;i<=n;i++){
			if(b[i].x1>=x1&&b[i].y1>=y1&&b[i].x2<=x2&&b[i].y2<=y2){
				ans.pb(i);
			}
		}
		printf("%d\n",ans.size());
		foreach(it,ans) printf("%d ",*it);
	}
	return 0;
}
/*
3
1 0 7 2
0 2 7 4
1 4 7 6
*/