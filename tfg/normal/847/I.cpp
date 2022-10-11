#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iic;

string mapa[251];
int n,m,p,q;
int noise[255][255];
int mkd[255][255];

int dir[]={1,0,-1,0};
int main() {
	int step=1;
	cin>>n>>m>>p>>q;
	fr(i,0,n)cin>>mapa[i];
	fr(i,0,n)fr(j,0,m){
		if(mapa[i][j]>='A'&&mapa[i][j]<='Z'){
			queue<iic> qu;
			step++;
			mkd[i][j]=step;
			qu.push(iic(ii(i,j),(mapa[i][j]-'A'+1)*p ));
			while(!qu.empty()){
				iic x=qu.front();
				qu.pop();
				int I=x.first.first;
				int J=x.first.second;
				int C=x.second;
				noise[I][J]+=C;
				if(C==1)continue;
				C>>=1;
				fr(z,0,4){
					int I2=I+dir[z];
					int J2=J+dir[z^1];
					if((I2>=0&&I2<n)&&(J2>=0&&J2<m)&&(mapa[I2][J2]!='*')&&(mkd[I2][J2]!=step)){
						qu.push(iic(ii(I2,J2),C));
						mkd[I2][J2]=step;
					}
				}
			}
		}
	}
	int cnt=0;
	/*fr(i,0,n){
		fr(j,0,m){
		printf("%3d",noise[i][j]);
		}
		cout<<endl;
	}*/
	fr(i,0,n)fr(j,0,m)if(noise[i][j]>q)cnt++;
	cout<<cnt<<endl;
}