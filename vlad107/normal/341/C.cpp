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

#define BASE 1000000007
#define N 500500

using namespace std;

long long f[N],fact[N];
int C[2222][2222],used[N],can[N],a[N];
int n,t,u;

int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
			if ((j==0)||(j==i))C[i][j]=1;else{
				C[i][j]=C[i-1][j]+C[i-1][j-1];
				if (C[i][j]>=BASE)C[i][j]-=BASE;
			}
	fact[0]=1;
	for (int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%BASE;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)if (a[i]>0)used[a[i]]=1;
	for (int i=0;i<n;i++)if (a[i]<0)can[i]=(!used[i+1]);
	for (int i=0;i<n;i++)t+=can[i];
	for (int i=0;i<n;i++)u+=(a[i]<0);
	for (int i=n;i>=0;i--)
		if (i>t)f[i]=0;else
		if (i==t)f[i]=fact[u-i];else{
			f[i]=(fact[u-i]*C[t][i])%BASE;
			for (int j=i+1;j<=t;j++){
				int r=(f[j]*C[j][i])%BASE;
				f[i]-=r;
				if (f[i]<0)f[i]+=BASE;
			}
		}
	cout<<f[0]<<endl;
}