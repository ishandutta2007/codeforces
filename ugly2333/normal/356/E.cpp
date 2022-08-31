//CF 356E_2
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
const int N = 111111;
const int Q = 19;
const int M = 26;
char ch[N];
int ss[M+5][N];
int sf[Q][N],hf[Q][N];
int gr[Q][N];
LL ans1[N],ans2[M][N];
int main()
{
	int n,i,j,k,l,x,y,z,t,b,c;
	LL l2,ans;
	scanf("%s",ch);
	n=strlen(ch);
	for(i=n;i>=1;i=i-1)
		ch[i]=ch[i-1];
	for(i=1;i<=n;i=i+1){
		x=ch[i]-'a';
		for(j=0;j<M;j=j+1)
			ss[j][i]=ss[j][i-1];
		ss[x][i]++;
	}
	for(i=1;i<=Q;i=i+1){
		x=1<<(i-1);
		for(j=1;j+x<=n;j=j+1){
			sf[i][j]=sf[i][j-1];
			hf[i][j]=hf[i][j-1];
			if(ch[j]!=ch[j+x]){
				//cout<<i<<j<<endl;
				sf[i][j]++;
				hf[i][j]=j;
			}
		}
	}
	for(i=1;i<=Q;i=i+1){
		l=(1<<i)-1;
		l2=(LL)l*l;
		for(j=1;j+l-1<=n;j=j+1){
			x=j;
			z=j+l-1;
			y=(x+z)/2;
			t=ch[y]-'a';
			if((l==1)||(gr[i-1][x]&&gr[i-1][y+1]&&sf[i][y-1]-sf[i][x-1]==0&&ss[t][z]-ss[t][x-1]==1))
				gr[i][j]=1;
			if(gr[i][j]){
				//cout<<i<<j<<endl;
				ans1[0]+=l2;
				ans1[x]-=l2;
				ans1[z+1]+=l2;
				for(k=0;k<M;k=k+1)
					if(k!=t&&ss[k][z]-ss[k][x-1]==0)
						ans2[k][y]+=l2;
			}
			else{
				if(sf[i][y-1]-sf[i][x-1]==0){
					if(gr[i-1][x]&&gr[i-1][y+1])
						for(k=0;k<M;k=k+1)
							if(ss[k][z]-ss[k][x-1]==0)
								ans2[k][y]+=l2;
				}
				else{
					if(sf[i][y-1]-sf[i][x-1]>=2)
						continue;
					b=hf[i][y-1];
					c=b+(1<<(i-1));
					//cout<<b<<c<<endl;
					if(gr[i-1][x]&&ss[t][c-1]-ss[t][x-1]==1&&ss[t][z]-ss[t][c]==0)
						ans2[ch[b]-'a'][c]+=l2;
					if(gr[i-1][y+1]&&ss[t][b-1]-ss[t][x-1]==0&&ss[t][z]-ss[t][b]==1)
						ans2[ch[c]-'a'][b]+=l2;
				}
			}
		}
	}
	ans=0;
	//cout<<ans1[0]<<endl;
	for(i=1;i<=n;i=i+1)
		ans1[i]+=ans1[i-1];
	for(i=1;i<=n;i=i+1)
		for(j=0;j<M;j=j+1){
			ans2[j][i]+=ans1[i];
			ans=max(ans,ans2[j][i]);
		}
	cout<<ans<<endl;
	return 0;
}