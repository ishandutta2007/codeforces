#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 int n,m,q;
cin >> n >> m >>q;
int* a=new int[n*m];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		int x;
		cin>>x;
		a[i*m+j]=1-x;
	}
}
std::vector<std::vector<int>> crow(n+1);
std::vector<std::vector<int>> ccol(m+1);

for(int i=0;i<n;i++){
	int sum=0;
	crow[i+1].push_back(0);
	for(int j=0;j<m;j++){
		sum+=a[i*m+j];
		crow[i+1].push_back(sum);
	}
}

for(int j=0;j<m;j++){
	int sum=0;
	ccol[j+1].push_back(0);
	for(int i=0;i<n;i++){
		sum+=a[i*m+j];
		ccol[j+1].push_back(sum);
	}
}

for(int i=0; i<q; i++){
	int op, x, y;
	cin>>op>>x>>y;
	if(op==1){
		int r=1-2*a[(x-1)*m+y-1];
		a[(x-1)*m+y-1]=1-a[(x-1)*m+y-1];
		for(int j=x; j<=n; j++) ccol[y][j]+=r;
		for(int j=y; j<=m; j++) crow[x][j]+=r;
	}
	if(op==2){
		if(a[(x-1)*m+y-1]==1){
			cout<<0<<endl;
			continue;
		}
		int maxr=1;
		int h=crow[x][y-1];
		int v=ccol[y][x-1];
		
		int currx1=x, currx2=x;
		int curry=y;
		
		while((curry<m)&&(h==crow[x][curry+1])) curry++;
		
		while(((currx2-currx1)<n-1)&&(curry>=y)){
			while((currx1>1)&&(crow[currx1-1][y-1]==crow[currx1-1][curry])) currx1--;
			while((currx2<n)&&(crow[currx2+1][y-1]==crow[currx2+1][curry])) currx2++;
			int r=((curry-y+1)*(currx2-currx1+1));
			if(r>maxr) maxr=r;
			curry--;
		}

		currx1=x; currx2=x; curry=y;
		while((curry>1)&&(h==crow[x][curry-2])) curry--;
		while(((currx2-currx1)<n-1)&&(curry<=y)){
			while((currx1>1)&&(crow[currx1-1][y]==crow[currx1-1][curry-1])) currx1--;
			while((currx2<n)&&(crow[currx2+1][y]==crow[currx2+1][curry-1])) currx2++;
			int r=((y-curry+1)*(currx2-currx1+1));
			if(r>maxr) maxr=r;
			curry++;
		}

		int currx=x;
		int curry1=y, curry2=y;

		while((currx<n)&&(v==ccol[y][currx+1])) currx++;
		
		while(((curry2-curry1)<m-1)&&(currx>=x)){
			while((curry1>1)&&(ccol[curry1-1][x-1]==ccol[curry1-1][currx])) curry1--;
			while((curry2<m)&&(ccol[curry2+1][x-1]==ccol[curry2+1][currx])) curry2++;
			int r=((currx-x+1)*(curry2-curry1+1));
			if(r>maxr) maxr=r;
			currx--;
		}

		curry1=y; curry2=y; currx=x;
		while((currx>1)&&(v==ccol[y][currx-2])) currx--;
		while(((curry2-curry1)<m-1)&&(currx<=x)){
			while((curry1>1)&&(ccol[curry1-1][x]==ccol[curry1-1][currx-1])) curry1--;
			while((curry2<m)&&(ccol[curry2+1][x]==ccol[curry2+1][currx-1])) curry2++;
			int r=((x-currx+1)*(curry2-curry1+1));
			if(r>maxr) maxr=r;
			currx++;
		}
		cout<<maxr<<endl;
	}

}





return 0;
}