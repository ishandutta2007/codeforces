#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<int,int> target;
map<int,int> cur;
int num;

vector<int> ans;

int N,M,P;

int a[200200],b[200200];

int main(){
	scanf("%d%d%d",&N,&M,&P);
	if((long long)M*P>1e8){
		printf("0\n\n");
		return 0;
	}
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<M;i++) scanf("%d",b+i);
	for(int i=0;i<M;i++) target[b[i]]++;
	int NUM=target.size();
	for(int i=0;i<P;i++){
		map<int,int> tmp;
		swap(cur,tmp);
		num=0;
		for(int j=0;j<M;j++){
			int x=a[i+j*P];
			if(cur[x]==target[x]-1){
				num++;
			}else if(cur[x]==target[x]){
				num--;
			}
			cur[x]++;
		}
		if(num==NUM) ans.push_back(i);
		for(int j=1;i+(j+M-1)*P<=N-1;j++){
			int x=a[i+(j-1)*P];
			if(cur[x]==target[x]) num--;
			else if(cur[x]==target[x]+1) num++;
			cur[x]--;
			x=a[i+(j+M-1)*P];
			if(cur[x]==target[x]) num--;
			else if(cur[x]==target[x]-1) num++;
			cur[x]++;
			
			if(num==NUM) ans.push_back(i+j*P);
		}
	}
	sort(ans.begin(),ans.end());
	if(ans.size()==0) printf("0\n\n");
	else{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d%c",ans[i]+1,i==ans.size()-1?'\n':' ');
	}
	return 0;
}