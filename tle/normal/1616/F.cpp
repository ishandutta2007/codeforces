#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int T,n,m;
#define S 288
#define NN 199999
int M=0,N=0,R[6000];
int ea[600][600];
int val[NN][S];
void sol() {
	cin>>n>>m;
	N=0,M=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j) ea[i][j]=0;
	memset(val,0,sizeof val);
	for(int i=1;i<=m;++i) {
		int x,y,z; cin>>x>>y>>z;
		if(x>y) swap(x,y);
		ea[x][y]=++N;
		if(z!=-1) {
			++M; val[M][N]=1; val[M][0]=z-1;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k) {
				if(ea[i][j]&&ea[j][k]&&ea[i][k]) {
					++M;
					val[M][ea[i][j]]+=1;
					val[M][ea[j][k]]+=1;
					val[M][ea[i][k]]+=1;
				}
			}
	int z=1;
	memset(R,0,sizeof R);
	for(int i=1;i<=N;++i) {
		int J=-1;
		for(int j=z;j<=M;++j) {
			if(val[j][i]) {
				J=j; break;
			}
		}
		if(J==-1) continue;
		R[i]=z;
		for(int i=0;i<S;++i) swap(val[J][i],val[z][i]);
		int w=val[z][i];
		for(int i=0;i<S;++i) val[z][i]=val[z][i]*w%3;
		for(int j=1;j<=M;++j) if(j!=z) {
			int o=val[j][i]%3;
			if(!o) continue;
			for(int k=0;k<S;++k) {
				val[j][k]=(val[j][k]-val[z][k]*o)%3;
			}
		}
		++z;
	}
//	for(int i=1;i<=M;++i) {
//		for(int j=0;j<10;++j)
//			cout<<val[i][j]<<",";
//		cout<<"\n";
//	}
//	for(int i=1;i<=N;++i)
//		printf("%d ",R[i]+1);
//	puts("ds");
	for(int i=1;i<=N;++i) if(R[i]) {
		R[i]=(val[R[i]][0]%3+3)%3;
	}
//	for(int i=1;i<=N;++i)
//		printf("%d ",R[i]+1);
//	puts("dm");
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if(ea[i][j]) ea[i][j]=R[ea[i][j]]+1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k) {
				if(ea[i][j]&&ea[j][k]&&ea[i][k]) {
					if((ea[i][j]+ea[j][k]+ea[i][k])%3) {
						puts("-1");
						return;
					}
				}
			}
//	cout<<"++\n";
	for(int i=1;i<=N;++i)
		printf("%d ",R[i]+1);
	puts("");
}
int main()
{
	cin>>T;
	while(T--) sol();
}