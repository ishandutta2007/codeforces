#include <bits/stdc++.h>
using namespace std;
char s[30][30];
int a[30][30],dp[30][30][30][30]; 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>s[i][j];
			a[i][j]=s[i][j]-'0';
		}
	int ans=0;
	for(int i=0;i<n;i++)
        for(int k=i;k<n;k++)
            for(int j=0;j<m;j++)
                for(int l=j;l<m;l++)
                {
                    int t=0;
                    for(int p=i;p<=k;p++)
        				for(int q=j;q<=l;q++)
        					t+=a[p][q];
        			dp[i][j][k][l]=t;
        			if(!dp[i][j][k][l])	ans=max(ans,(k-i+l-j+2)*2);
                }
	cout<<ans<<endl;
}