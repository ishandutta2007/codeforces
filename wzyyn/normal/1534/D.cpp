#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > ve;
int n,a[2005],b[2005];

void Update(int x){
	int y;
	printf("? %d\n",x);
	fflush(stdout);
	for (int i=1;i<=n;i++){
		scanf("%d",&y);
		if (y==1) ve.push_back(make_pair(i,x));
	}
		
}
int main(){
	scanf("%d",&n);
	printf("? 1\n");
	fflush(stdout);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for (int i=1;i<=n;i++)
		sum+=(a[i]&1);
	if (sum<=(n+1)/2-1){
		for (int i=1;i<=n;i++)
			if (a[i]&1) Update(i);
	}
	else{
		for (int i=1;i<=n;i++)
			if (a[i]==1) ve.push_back(make_pair(i,1));
		for (int i=2;i<=n;i++)
			if (!(a[i]&1)) Update(i);
	}
	printf("!\n");
	for (auto i:ve) printf("%d %d\n",i.first,i.second);
}