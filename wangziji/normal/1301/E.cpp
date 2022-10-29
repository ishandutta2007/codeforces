#include <iostream>
#include <cstdio>
using namespace std;
int a[505][505];
unsigned short qzh[255][505][505];
int main(int argc, char** argv) {
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin >> c;
			if(c=='G') a[i][j]=1;
			if(c=='Y') a[i][j]=2;
			if(c=='B') a[i][j]=3;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout << a[i][j];
		puts(""); 
	}
	puts("");*/
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=n-i-i+1;j++)
		{
			for(int k=1;k<=m-i-i+1;k++)
			{
				if(i>1&&!qzh[i-1][j+1][k+1]) continue;
				qzh[i][j][k]=1;
		//		cout << "===================================\n";
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=k;l<k+i;l++) if(a[j][l]!=0){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=k+i;l<k+i+i;l++) if(a[j][l]!=1){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=k;l<k+i;l++) if(a[j+i+i-1][l]!=2){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=k+i;l<k+i+i;l++) if(a[j+i+i-1][l]!=3){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=j;l<j+i;l++) if(a[l][k]!=0){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=j+i;l<j+i+i;l++) if(a[l][k]!=2){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=j;l<j+i;l++) if(a[l][k+i+i-1]!=1){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
				for(int l=j+i;l<j+i+i;l++) if(a[l][k+i+i-1]!=3){qzh[i][j][k]=0;break;}
				if(!qzh[i][j][k]) continue;
		//		cout << i << " " << j << " " << k  << "\n";
			}
		}
	}
	//cout << qzh[2][1][7] << "\n";
	/*for(int i=1;i<=1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				cout << qzh[i][j][k];
			}
			puts("");
		}
		puts("");
	}*/
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				qzh[i][j][k]+=qzh[i][j][k-1]+qzh[i][j-1][k]-qzh[i][j-1][k-1];
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				cout << qzh[i][j][k];
			}
			puts("");
		}
		puts("");
	}*/
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int l=1,r=min(x2-x1+1,y2-y1+1)/2,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int X2=x2-mid-mid+1,Y2=y2-mid-mid+1;
			if(X2>=x1&&Y2>=y1&&qzh[mid][X2][Y2]-qzh[mid][x1-1][Y2]-qzh[mid][X2][y1-1]+qzh[mid][x1-1][y1-1]>0) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans*ans*4);
	}
	return 0;
}