#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define C 333
#define N 101500

using namespace std;

int f[C][N],n,m,k,kg[N],rev[N],ver[N],kn,was[N],Q,ct;
long long a[N],sum[N],add[N];
vector<int>u[N];

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d\n",&n,&m,&k);
	for (int i=0;i<n;i++)scanf("%I64d",&a[i]);
	for (int i=0;i<m;i++){
		scanf("%d",&kg[i]);
		for (int j=0;j<kg[i];j++){
			int x;
			scanf("%d",&x);
			--x;
			u[i].pb(x);
		}
		sort(u[i].begin(),u[i].end());
	}	
	for (int i=0;i<m;i++)
		if (kg[i]>=C){
			Q++;
			for (int j=0;j<kg[i];j++){
				was[u[i][j]]=Q;
				sum[kn]+=a[u[i][j]];
			}
			rev[i]=kn;
			ver[kn]=i;
			kn++;
			for (int j=0;j<m;j++){
				if (j==i)continue;
				if (kg[j]>=C){
					int e1=0,e2=0,ct=0;
					while ((e1<kg[i])&&(e2<kg[j])){
						if (u[i][e1]==u[j][e2]){
							e1++;e2++;
							ct++;
							continue;
						}
						if (u[i][e1]<u[j][e2])e1++;else e2++;
					}
					f[rev[i]][j]=ct;
				}else{
					ct=0;
					for (int e=0;e<kg[j];e++)
						if (was[u[j][e]]==Q)ct++;
					f[rev[i]][j]=ct;
				}
			}
		}
	scanf("\n");
	for (int i=0;i<k;i++){
		int x,y;
		char q;
		scanf("%c",&q);
		if (q=='?'){
			scanf("%d\n",&x);
			--x;
			long long ans=0;
			for (int j=0;j<kn;j++)
				if (ver[j]!=x)ans+=add[j]*1ll*f[j][x];
			if (kg[x]>=C)
				ans+=sum[rev[x]];
			else{
				for (int j=0;j<kg[x];j++)ans+=a[u[x][j]];
			}
			printf("%I64d\n",ans);
		}else{
			scanf("%d%d\n",&x,&y);
			--x;
			if (kg[x]>=C){
				add[rev[x]]+=y;
				sum[rev[x]]+=kg[x]*1ll*y;
			}else{
				for (int j=0;j<kn;j++)
					sum[j]+=f[j][x]*1ll*y;
				for (int j=0;j<kg[x];j++)a[u[x][j]]+=y;
			}
		}
	}
}