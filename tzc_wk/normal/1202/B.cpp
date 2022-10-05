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
#define int long long
string s;
int a[11][11][11],ans[11][11];
signed main(){
	cin>>s;
	memset(ans,0,sizeof(ans));
	memset(a,63,sizeof(a));
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++){
				for(int p=0;p<=10;p++){
					for(int q=0;q<=10;q++){
						if((i*p+j*q)%10==k){
							int x=k;
							if(x==0)	x=10;
							if(x==10&&(p==0&&q==0))	continue;
							a[i][j][x]=min(a[i][j][x],p+q);
						}
					}
				}
				int x=k;
				if(x==0)	x=10;
//				cout<<i<<" "<<j<<" "<<k<<" "<<a[i][j][x]<<endl;
			}
	for(int i=0;i<s.size()-1;i++){
		int dig1=s[i]-'0',dig2=s[i+1]-'0';
		int dif=(dig2-dig1+20)%10;
		if(dif==0)	dif=10;
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					if(~ans[j][k]){
						if(a[j][k][dif]==0x3f3f3f3f3f3f3f3f)	ans[j][k]=-1;
						else{
							ans[j][k]+=a[j][k][dif]-1;
						}
					}
				}
			}
		
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(ans[i][j]==-1)	cout<<"-1 ";
			else				cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}