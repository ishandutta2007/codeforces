#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 1005
using namespace std;
int num[2][maxn];
bool vis1[maxn],vis2[maxn];
int n;
void read(int x){
	char ch;
	int cnt=0;
	ch=getchar();
	while(ch!='\n'&&ch!=EOF){
		num[x][cnt++]=ch-'0';
		ch=getchar();
	}
	return;
}

void work(){
	sort(num[0],num[0]+n);
	sort(num[1],num[1]+n);
	int ans1=0,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((!vis1[j])&&num[1][j]>=num[0][i]){
				vis1[j]=1;
				break;
			}
		}
		if(j==n)continue;
		ans1++;
	}
	printf("%d\n",n-ans1);
	int ans2=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((!vis2[j])&&num[1][j]>num[0][i]){
				vis2[j]=1;
				break;
			}
		}
		if(j==n)continue;
		ans2++;
	}
	printf("%d",ans2);
	return;
}

int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d\n",&n);
	read(0);read(1);
	work();
	return 0;
}