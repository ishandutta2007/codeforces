#include<cstdio>
#include<algorithm>

using namespace std;

int a[5050][5050];
int cnt[5050][5050];

char ch[5050];

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s",ch);
		ch[M]='0';
		int r=-1;
		for(int j=0;j<M;j++){
			if(r>j){
				cnt[j][j]++;
				cnt[j][r]--;
			}else{
				if(ch[j]=='0') continue;
				for(r=j;r<=M;r++){
					if(ch[r]=='0') break;
				}
				cnt[j][j]++;
				cnt[j][r]--;
			}
		}
	}
	for(int i=0;i<M;i++){
		for(int j=i+1;j<M;j++){
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	int ans=0;
	for(int i=0;i<M;i++) for(int j=i;j<M;j++){
		int a=j-i+1;
		ans=max(ans,a*cnt[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}