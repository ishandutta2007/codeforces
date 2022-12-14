#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int ln[110];
int a[110][110];

vector<int> vec;

int main(){
	scanf("%d",&N);
	int fi=0,se=0;
	for(int i=0;i<N;i++){
		scanf("%d",ln+i);
		for(int j=0;j<ln[i];j++){
			scanf("%d",&a[i][j]);
		}
		int n=ln[i]/2;
		for(int j=0;j<n;j++) fi+=a[i][j];
		for(int j=0;j<n;j++) se+=a[i][ln[i]-1-j];
		if(ln[i]%2==1){
			vec.push_back(a[i][n]);
		}
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	bool which=true;
	for(int i=0;i<vec.size();i++){
		if(which) fi+=vec[i];
		else se+=vec[i];
		which=!which;
	}
	printf("%d %d\n",fi,se);
	return 0;
}