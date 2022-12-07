#include<bits/stdc++.h>

using namespace std;

const int N=105;
const int M=55;
char s[12][N],t[N];
int nx[12][N][M],l[12],n;
int Mask[55],f[55][1055];
int fr1[55][1055];
int fr2[55][1055];
vector<int> v[12][55];
void solve(){
	scanf("%d",&n);
	memset(nx,-1,sizeof(nx));
	for (int i=0;i<n;i++){
		for (int j=0;j<52;j++)
			v[i][j].resize(0);
		scanf("%s",s[i]+1);
		l[i]=strlen(s[i]+1);
		for (int j=l[i];j>=1;j--){
			if (s[i][j]>='A'&&s[i][j]<='Z') s[i][j]-='A';
			if (s[i][j]>='a'&&s[i][j]<='z') s[i][j]-='a'-26;
			memcpy(nx[i][j],nx[i][j+1],sizeof(nx[i][j]));
			nx[i][j][s[i][j]]=j;
		}
		for (int j=1;j<=l[i];j++)
			v[i][s[i][j]].push_back(j);
	}
	//cout<<233<<endl;
	for (int i=0;i<52;i++){
		Mask[i]=0;
		for (int j=0;j<n;j++)
			if (v[j][i].size()==0)
				Mask[i]=-1;
			else if (v[j][i].size()==2)
				Mask[i]|=1<<j;
	}
	//cout<<233<<endl;
	memset(f,0,sizeof(f));
	memset(fr1,-1,sizeof(fr1));
	memset(fr2,-1,sizeof(fr2));
	int ans=0,ansi=-1,ansj=-1;
	for (int i=1;i<=l[0];i++){
		int c=s[0][i];
		if (Mask[c]==-1) continue;
		for (int j=0;j<1<<n;j++)
			if ((j&Mask[c])==j){
				static int loc[12];
				for (int k=0;k<n;k++)
					loc[k]=(j&(1<<k)?v[k][c][1]:v[k][c][0]);
				if (loc[0]!=i) continue;
				if ((++f[c][j])>ans){
					ans=f[c][j];
					ansi=c; ansj=j;
				}
				for (int nc=0;nc<52;nc++){
					bool flag=0;
					int nj=0;
					for (int p=0;p<n;p++){
						if (nx[p][loc[p]+1][nc]==-1) flag=1;
						else{
							int nloc=nx[p][loc[p]+1][nc];
							if (v[p][nc].size()==2)
								if (nloc==v[p][nc][1])
									nj|=1<<p;
						}
					}
					if (!flag)
						if (f[nc][nj]<f[c][j]){
							f[nc][nj]=f[c][j];
							fr1[nc][nj]=c;
							fr2[nc][nj]=j;
						}
				}
			}
	}
	cout<<ans<<endl;
	t[ans]=0;
	for (;ansi!=-1&&ansj!=-1;){
		t[--ans]=(ansi<26?ansi+'A':ansi+'a'-26);
		int ni=fr1[ansi][ansj];
		int nj=fr2[ansi][ansj];
		ansi=ni; ansj=nj;
	}
	printf("%s\n",t);
}

int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
}