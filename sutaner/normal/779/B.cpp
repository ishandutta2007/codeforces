#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 25
using namespace std;
char num[maxn];
bool vis[maxn],f=0;
int k,cnt=0,ans=0;
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%s%d",num,&k);
	int len=strlen(num);
	for(int i=len-1;i>=0;i--){
		if(num[i]!='0')
			ans++;
		else 
			cnt++;
		if(cnt==k){
			printf("%d",ans);
			return 0;
		}
	}
	printf("%d",ans+cnt-1);
	return 0;
}