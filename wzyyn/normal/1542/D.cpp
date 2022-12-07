#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505;
const int mo=998244353;
int fl[N],v[N],f[N],n,ans;
void Upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char s[5];
		scanf("%s",s+1);
		if (s[1]=='-') fl[i]=1;
		else scanf("%d",&v[i]);
	}
	for (int i=1;i<=n;i++) if (!fl[i]){
		memset(f,0,sizeof(f));
		int S=0; f[0]=1;
		for (int j=1;j<=n;j++){
			if (j==i) continue;
			if (fl[j]==0){
				if (v[i]>v[j]||(v[i]==v[j]&&j<i)){
					for (int k=S;k>=0;k--)
						Upd(f[k+1],f[k]);
					++S;
				}
				else{
					for (int k=S;k>=0;k--)
						Upd(f[k],f[k]);
				}
			}
			else{
				if (j<i) Upd(f[0],f[0]);
				for (int k=0;k<=S;k++)
					Upd(f[k],f[k+1]);
			}
		}
		int way=0;
		for (int j=0;j<=S;j++)
			Upd(way,f[j]);
		ans=(ans+1ll*v[i]*way)%mo;
	}
	cout<<ans<<endl;
}