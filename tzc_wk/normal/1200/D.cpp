#include <bits/stdc++.h>
using namespace std;
int n,k,c[2005][2005];
int s1[2005],s2[2005];
int sum1[2005][2005],sum2[2005][2005],a1[2005][2005],a2[2005][2005];
int ans=0;
int main(){
	cin>>n>>k;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		char s;cin>>s;
    		if(s=='B')	c[i][j]=1;
		}
	}
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++)	if(c[i][j])	flag=0;
        s1[i]=s1[i-1]+flag;
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++)	if(c[j][i])	flag=0;
        s2[i]=s2[i-1]+flag;
    }
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			sum1[i][j]=sum1[i][j-1]+c[i][j];
			sum2[i][j]=sum2[i-1][j]+c[i][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int k1=sum1[i][j-1]+(sum1[i][n]-sum1[i][j+k-1]); 
			int k2=sum2[i-1][j]+(sum2[n][j]-sum2[i+k-1][j]);
			a1[i][j]=(k1==0);
			a2[i][j]=(k2==0);
			a1[i][j]=a1[i-1][j]+a1[i][j];
			a2[i][j]=a2[i][j-1]+a2[i][j];
		}
	for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=n-k+1;j++){
			ans=max(ans,
			s1[n]-s1[i+k-1]+s1[i-1]+a1[i+k-1][j]-a1[i-1][j]+
			s2[n]-s2[j+k-1]+s2[j-1]+a2[i][j+k-1]-a2[i][j-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}