#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

char ch[100100];
int N;

int cnt[4];

int main(){
	scanf("%d",&N);
	scanf("%s",ch);
	for(int i=0;i<N;i++){
		if(ch[i]=='A'){
			cnt[0]++;
		}else if(ch[i]=='T'){
			cnt[1]++;
		}else if(ch[i]=='G'){
			cnt[2]++;
		}else{
			cnt[3]++;
		}
	}
	int Ma=-1;
	for(int i=0;i<4;i++) Ma=max(Ma,cnt[i]);
	int num=0;
	for(int i=0;i<4;i++) if(cnt[i]==Ma) num++;
	long long ans=1;
	for(int i=0;i<N;i++){
		ans*=num;
		ans%=mod;
	}
	printf("%d\n",(int)ans);
	return 0;
}