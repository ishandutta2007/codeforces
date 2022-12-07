#include<bits/stdc++.h>

using namespace std;

int n,m,ans,ans1;
int d[55][55],r[55][55];
int ix[250005],iy[250005];
char s[55];

void turn(int x,int y){
	ans++;
	ix[ans] = x,iy[ans] = y;
	d[x][y+1] ^= 1,d[x][y] ^= 1,r[x][y] ^= 1,r[x+1][y] ^= 1; 
}

void rotate1(int x,int y){
	if(d[x][y+1]){turn(x,y);return;}
	if(d[x+1][y+1])rotate1(x+1,y+1);
	turn(x,y+1);turn(x,y);
}

void rotate2(int x,int y){
	if(r[x+1][y]){turn(x,y);return;}
	if(r[x+1][y+1])rotate2(x+1,y+1);
	turn(x+1,y);turn(x,y);
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D_new.out","w",stdout);
	cin >> n >> m;
	int i,j;
	for(i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(j = 1;j <= m;j++){
			if(s[j] == 'U')d[i][j] = 1;
			if(s[j] == 'L')r[i][j] = 1;
		}
	}
	ans = 0;
	if(!(m & 1)){
		for(i = 1;i <= n - 1;i++)
			for(j = 1;j <= m;j++)if(d[i][j])rotate1(i,j);	
	}
	else{
		for(j = 1;j <= m - 1;j++)
			for(i = 1;i <= n;i++)if(r[i][j])rotate2(i,j);
	}
	ans1 = ans;
	memset(d,0,sizeof(d));
	memset(r,0,sizeof(r));
	for(i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(j = 1;j <= m;j++){
			if(s[j] == 'U')d[i][j] = 1;
			if(s[j] == 'L')r[i][j] = 1; 
		}
	}
	if(!(m & 1)){
		for(i = 1;i <= n - 1;i++)
			for(j = 1;j <= m;j++)if(d[i][j])rotate1(i,j);	
	}
	else{
		for(j = 1;j <= m - 1;j++)
			for(i = 1;i <= n;i++)if(r[i][j])rotate2(i,j);
	}
	cout<<ans<<endl;
	for(i = 1;i <= ans1;i++)cout<<ix[i]<<" "<<iy[i]<<endl;
	for(i = ans;i > ans1;i--)cout<<ix[i]<<" "<<iy[i]<<endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0; 
}