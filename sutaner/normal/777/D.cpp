#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 2000005
using namespace std;
int n,ans=0;
char name[maxn],ch;
int pos[maxn];int cnt2=0;
int size[maxn];
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d\n",&n);
	ch=getchar();int cnt=0;
	while(ch!=EOF){
		if(ch=='\n'){
			ch=getchar();
			continue;
		}
		if(ch=='#')
			pos[cnt2++]=cnt;
		name[cnt++]=ch;
		ch=getchar();
	}
	pos[n]=cnt;
	size[n-1]=pos[n]-pos[n-1];
	for(int i=n-2;i>=0;i--){
		int size1=pos[i+1]-pos[i];
		int size2=size[i+1];
		for(int k=1;k<min(size1,size2);k++){
			if(name[k+pos[i]]!=name[k+pos[i+1]]){
				if(name[k+pos[i]]<name[k+pos[i+1]]){
					size[i]=size1;
					goto jump;
				}else{
					size[i]=k;
					ans+=size1-k;
					goto jump;
				}
			}
		}
		if(size1<=size2){
			size[i]=size1;
			jump:continue;
		}
		else{
			ans+=size1-size2;
			size[i]=size2;
			continue;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<size[i];j++){
			printf("%c",name[pos[i]+j]);
		}
		printf("\n");
	}
	return 0;
}