#include <cstdio>
#include <list>
#define max_d 500
#define max_s 5000
using namespace std;
int d;
int dp[max_d][max_s+1],len[max_d][max_s+1];
bool vis[max_d][max_s+1],in[max_d][max_s+1];
list<int> remain;
list<int> sum;
list<int> r[max_d];
void print(int remain,int sum){
	if(!sum&&!remain)
		return;
	putchar(dp[remain][sum]|'0');
	print((remain*10+dp[remain][sum])%d,sum-dp[remain][sum]);
}
bool ans(int s){
	bool flag=0;
//	int clck=1000000;
	while(!remain.empty()){
		const int nowr=remain.front(),nows=sum.front();
		if(nows==s&&!nowr){
			flag=1;
			return 1;
		}
//		if(!--clck)
//			return flag;
		remain.pop_front(),sum.pop_front();
		in[nowr][nows]=0;
		if(nows>=s)
			continue;
		for(register int i=0; i<10; ++i){
			const int bef=(nowr+d-i%d)%d,befs=nows+i;
			if(befs>s)
				break;
			for(auto it=r[bef].begin(); it!=r[bef].end(); ++it){
				const int befr=*it;
//				printf("%d %d\n",befr,bef);
				if(!vis[befr][befs]){
					vis[befr][befs]=1;
					in[befr][befs]=1;
					dp[befr][befs]=i;
					len[befr][befs]=len[nowr][nows]+1;
					remain.push_back(befr);
					sum.push_back(befs);
					continue;
				}
				if(dp[befr][befs]>i&&len[befr][befs]==len[nowr][nows]+1){
					dp[befr][befs]=i;
//					remain.push_back(befr);
//					sum.push_back(befs);
					continue;
				}
				if(len[befr][befs]>len[nowr][nows]+1){
					dp[befr][befs]=i;
					len[befr][befs]=len[nowr][nows]+1;
//					remain.push_back(befr);
//					sum.push_back(befs);
					continue;
				}
			}
		}
	}
	return flag;
}
int main(){
	int s;
	scanf("%d%d",&d,&s);
	for(int i=0; i<d; ++i)
		r[i].clear();
	for(int i=0; i<d; ++i)
		r[i*10%d].push_back(i);
	remain.clear(),sum.clear();
	remain.push_back(0),sum.push_back(0);
	if(ans(s))
		print(0,s);
	else
		puts("-1");
	return 0;
}