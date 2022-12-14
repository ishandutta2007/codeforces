#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int main()
{
	int n,m,x=-1,y=-1;
	char boa[510][510];
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
        scanf(" %s",boa[i]);
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(boa[i][j]=='*'&&boa[i-1][j]=='*'&&boa[i][j-1]=='*'&&boa[i+1][j]=='*'&&boa[i][j+1]=='*')
            {
                x=i;
                y=j;
            }
        }
    }
    if(x==-1)
    {
        printf("NO");
        return 0;
    }
    boa[x][y]='.';
    for(int i=x+1,j=y;i<n&&boa[i][j]=='*';i++)boa[i][j]='.';
    for(int i=x-1,j=y;i>=0&&boa[i][j]=='*';i--)boa[i][j]='.';
    for(int i=x,j=y+1;j<m&&boa[i][j]=='*';j++)boa[i][j]='.';
    for(int i=x,j=y-1;j>=0&&boa[i][j]=='*';j--)boa[i][j]='.';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(boa[i][j]=='*')
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
	return 0;
}